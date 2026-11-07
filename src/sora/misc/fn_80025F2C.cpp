#include <types.h>
#include <revolution/OS/OSMutex.h>
#pragma force_active on
struct Block { u32 unused; u32 size; Block* next; char pad[7]; u8 flags; };
struct Heap { char pad[0x14]; u16 count; char pad2[6]; u32 used; Block* head; u8 lock; char pad3[3]; OSMutex mutex; };
struct Guard { OSMutex* mutex; unsigned char lock : 8; };
extern "C" void fn_80025F2C(Heap* heap, void* ptr) {
    Guard guard;
    guard.mutex = &heap->mutex;
    guard.lock = heap->lock;
    if (guard.lock) OSLockMutex(guard.mutex);
    if (ptr) {
        Block* next;
        u32 size;
        Block* current;
        Block* block;
        block = *(Block**)((char*)ptr - 12);
        current = heap->head;
        size = block->size;
        if (!(block->flags & 1)) {
            while (current < (next = current->next)) {
                if (current < block && block < next) break;
                current = next;
            }
            if ((char*)block + size == (char*)next) {
                block->size += next->size;
                block->next = current->next->next;
            } else block->next = next;
            u32 currentSize = current->size;
            if ((char*)current + currentSize == (char*)block) {
                current->size = currentSize + block->size;
                current->next = block->next;
            } else current->next = block;
            block->flags |= 1;
            *(u32*)((char*)ptr - 4) = 0xDDDDDDDD;
            heap->count--;
            heap->used -= size;
        }
    }
    if (guard.lock) OSUnlockMutex(guard.mutex);
}