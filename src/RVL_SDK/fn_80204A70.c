#include <types.h>
#include <revolution/OS/OSMutex.h>
#include <string.h>
#pragma force_active on
typedef struct H { char pad[0x20]; OSMutex mutex; u32 flags; u32 head; u32 tail; } H;
static inline u32 head_alloc(H* h, u32 size, s32 align) {
    u32 old = h->head;
    u32 start = (align + old - 1) & ~(align - 1);
    u32 end = size + start;
    u32 length;
    if (end > h->tail) return 0;
    length = end - old;
    if (h->flags & 1) memset((void*)old, 0, length);
    h->head = end;
    return start;
}
static inline u32 tail_alloc(H* h, u32 size, s32 align) {
    u32 old = h->tail;
    u32 start = (old - size) & ~(align - 1);
    u32 length;
    if (start < h->head) return 0;
    length = old - start;
    if (h->flags & 1) memset((void*)start, 0, length);
    h->tail = start;
    return start;
}
u32 fn_80204A70(H* h, u32 size, s32 align) {
    u32 result;
    if (size == 0) size = 1;
    size = (size + 3) & ~3;
    if (h->flags & 4) OSLockMutex(&h->mutex);
    if (align >= 0) result = head_alloc(h, size, align);
    else result = tail_alloc(h, size, -align);
    if (h->flags & 4) OSUnlockMutex(&h->mutex);
    return result;
}