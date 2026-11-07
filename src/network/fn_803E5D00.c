#include <revolution/VF/pf_critical.h>
#pragma force_active on
typedef struct Volume Volume;
typedef struct Entry Entry;
typedef struct File File;
struct Volume { unsigned short size; char pad0[0x1e]; unsigned char shift; char pad1[0x1f80-0x21]; int error; char pad2[0xc]; char critical[1]; };
struct Entry { unsigned int flags; char pad0[0x34]; Volume *volume; char pad1[0x264-0x3c]; unsigned int length; Volume *owner; };
struct File { char pad0[8]; Entry *entry; char pad1[0xc]; int error; unsigned int position; int cluster; unsigned int sector; unsigned short offset; };
extern char lbl_805644C0[];
extern int fn_803E9974(void *);
int fn_803E5D00(File *file, unsigned int delta, int origin)
{
    Volume *volume;
    Volume *v;
    unsigned int old, magnitude, pos;
    int result;
    if (file == 0) volume = 0;
    else volume = file->entry->owner;
    PF_enterCritical(volume->critical);
    result = fn_803E9974(volume);
    if (result != 0) {
        PF_exitCritical(volume->critical);
        *(int *)(lbl_805644C0 + 0x40) = result;
        volume->error = result;
        return result;
    }
    if (!(file->entry->flags & 1) || !(file->entry->flags & 2)) {
        PF_exitCritical(volume->critical);
        *(int *)(lbl_805644C0 + 0x40) = 0x26;
        volume->error = 0x26;
        return 0x26;
    }
    switch (origin) {
    case 1: pos = file->position; break;
    case 0: pos = 0; break;
    case 2: pos = file->entry->length; break;
    default:
        PF_exitCritical(volume->critical);
        *(int *)(lbl_805644C0 + 0x40) = 10;
        file->entry->volume->error = 10;
        file->error = 10;
        return 10;
    }
    if (delta & 0x80000000) {
        magnitude = (~delta & 0x7fffffff) + 1;
        if (pos < magnitude) {
            PF_exitCritical(volume->critical);
            *(int *)(lbl_805644C0 + 0x40) = 10;
            file->entry->volume->error = 10;
            file->error = 10;
            return 10;
        }
        pos -= magnitude;
    } else {
        if (delta > 0xffffffff - pos) {
            PF_exitCritical(volume->critical);
            *(int *)(lbl_805644C0 + 0x40) = 0x25;
            file->entry->volume->error = 0x25;
            file->error = 0x25;
            return 0x25;
        }
        pos += delta;
    }
    file->cluster = -1;
    file->position = 0;
    if (file == 0) v = 0;
    else v = file->entry->owner;
    old = file->position;
    file->sector = old >> v->shift;
    file->offset = old & (v->size - 1);
    file->position = pos;
    if (file == 0) v = 0;
    else v = file->entry->owner;
    old = file->position;
    file->sector = old >> v->shift;
    file->offset = old & (v->size - 1);
    PF_exitCritical(volume->critical);
    return result;
}