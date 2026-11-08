#include <revolution/VF/pf_critical.h>
#pragma force_active on
typedef struct Volume Volume;
typedef struct Entry Entry;
typedef struct Handle Handle;
struct Volume { char pad0[0x1620]; unsigned int count; char pad1[0x1f80-0x1624]; int error; char pad2[0xc]; char critical[1]; };
struct Entry { unsigned int flags; unsigned short count; char pad[0x26c-6]; Volume *owner; };
struct Handle { unsigned int flags; Entry *entry; };
extern char lbl_805644C0[];
extern int fn_803E9974(void *);
int fn_803DC358(Handle *handle)
{
    Volume *volume;
    int result;
    if (handle == 0) volume = 0;
    else volume = handle->entry->owner;
    PF_enterCritical(volume->critical);
    result = fn_803E9974(volume);
    if (result != 0) {
        PF_exitCritical(volume->critical);
        *(int *)(lbl_805644C0 + 0x40) = result;
        volume->error = result;
        return result;
    }
    if (!(handle->entry->flags & 1) || !(handle->entry->flags & 2)) {
        PF_exitCritical(volume->critical);
        *(int *)(lbl_805644C0 + 0x40) = 10;
        volume->error = 10;
        return 10;
    }
    if (--handle->entry->count == 0)
        handle->entry->flags &= ~1;
    handle->flags &= ~1;
    volume->count--;
    PF_exitCritical(volume->critical);
    return 0;
}