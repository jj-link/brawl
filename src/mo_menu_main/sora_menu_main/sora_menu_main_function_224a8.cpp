#pragma force_active on
extern "C" {
extern void* g_GameGlobal;
unsigned int* fn_8004E5EC(void*);
int fn_8004F2BC(int);
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
void* memcpy(void*, const void*, unsigned long);
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

inline bool anyAvailable(unsigned int* bits) {
    for (int i = 5; i < 0x79; ++i) {
        if (available(bits, i))
            return true;
    }
    return false;
}

extern "C" void fn_2_224A8(Menu* self) {
    int entries[6];
    int count = 0;
    unsigned int* bits = fn_8004E5EC(g_GameGlobal);

    if (anyAvailable(bits)) {
        entries[count++] = 0x79;
    }

    bits = fn_8004E5EC(g_GameGlobal);
    for (int i = 0; i < 5; ++i) {
        if (available(bits, i))
            entries[count++] = i;
    }

    self->entries = (int*)alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(
        0x2a, count * 4);
    memcpy(self->entries, entries, count * 4);
    self->count = count;
}
