#pragma force_active on
extern "C" {
extern void* g_GameGlobal;
unsigned int* fn_8004E5F8(void*);
int fn_2_1D1E8(const void*, const void*);
void fn_803F8ACC(void*, unsigned int, unsigned int,
                 int (*)(const void*, const void*));
void* fn_80024A18(int, unsigned int);
void* memcpy(void*, const void*, unsigned int);
}

struct Menu {
    char pad[0x678];
    int* entries;
    int count;
};

extern "C" void fn_2_1D270(Menu* self) {
    int entries[128];
    int count = 0;
    unsigned int* bits = fn_8004E5F8(g_GameGlobal);
    int* out = entries;

    for (int i = 0; i < 117; ++i) {
        int bit = i * 2 + 1;
        if (bits[bit / 32] & (1 << (bit % 32))) {
            *out++ = i;
            ++count;
        }
    }

    if (count > 0) {
        fn_803F8ACC(entries, count, 4, fn_2_1D1E8);
        self->entries = (int*)fn_80024A18(42, count * 4);
        memcpy(self->entries, entries, count * 4);
    } else {
        self->entries = 0;
    }

    self->count = count;
}
