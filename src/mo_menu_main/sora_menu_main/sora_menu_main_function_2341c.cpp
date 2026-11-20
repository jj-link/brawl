#pragma force_active on
#include <gf/gf_heap_manager.h>
extern "C" {
extern void* g_GameGlobal;
unsigned int* fn_8004E5EC(void*);
int fn_8004F2BC(int);
}

struct Menu {
    char pad[0x674];
    int* entries;
    unsigned char count;
};

inline bool available(unsigned int* bits, int entry) {
    int id = fn_8004F2BC(entry);
    if (id != 0x74)
        return (bits[id / 32] & (1 << (id % 32))) != 0;
    return true;
}

extern "C" void fn_2_2341C(Menu* self) {
    int off;
    int count = 0;
    int entry;
    int i;
    unsigned int* bits;
    self->entries = (int*)gfHeapManager::alloc((Heaps::HeapType)0x2a, 0x1d0);
    bits = fn_8004E5EC(g_GameGlobal);
    i = 0;
    off = 0;
    do {
        entry = i + 5;
        if (available(bits, entry)) {
            count++;
            *(int*)((char*)self->entries + off) = entry;
            off += 4;
        }
        i++;
    } while (i < 0x74);
    self->count = count;
}