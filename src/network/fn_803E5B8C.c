#include <revolution/VF/pf_critical.h>
#include <revolution/VF/pf_entry.h>
#pragma force_active on

typedef struct Volume Volume;
typedef struct Entry Entry;
typedef struct File File;
struct Volume {
    char pad0[0x1644];
    File *current;
    char pad1[0x1f80 - 0x1648];
    int error;
    char pad2[0xc];
    char critical[1];
};
struct Entry {
    unsigned int flags;
    char pad0[0x38 - 4];
    Volume *volume;
    char pad1[0x25e - 0x3c];
    unsigned short previous;
    unsigned short time;
    unsigned short date;
    char pad2[4];
    Volume *owner;
};
struct File {
    char pad0[8];
    Entry *entry;
    char pad1[0xc];
    int error;
};
extern char lbl_805644C0[];
extern int fn_803E9B64(void *);
extern int fn_803E530C(void *, int, int, int, void *, int *);

int fn_803E5B8C(int a, int b, int c, File *file, int *out)
{
    int n;
    int result;
    Volume *volume;
    *out = 0;
    if (file == 0)
        volume = 0;
    else
        volume = file->entry->owner;
    PF_enterCritical(volume->critical);
    result = fn_803E9B64(volume);
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
    volume->current = file;
    result = fn_803E530C(volume, a, b, c, file, &n);
    *out = n;
    volume->current = 0;
    if (result != 0) {
        *(int *)(lbl_805644C0 + 0x40) = result;
        file->entry->volume->error = result;
        file->error = result;
    }
    if (n != 0) {
        PFENT_getcurrentDateTimeForEnt(&file->entry->date, &file->entry->time);
        file->entry->previous = file->entry->date;
        file->entry->flags |= 4;
    }
    PF_exitCritical(volume->critical);
    return result;
}