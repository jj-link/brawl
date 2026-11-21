#pragma force_active on
#pragma opt_strength_reduction off

extern "C" void fn_802E7554(int, void*, void**, int, int, void*);

struct Entry {
    unsigned char pad0[0x10];
    float f0, f1, f2, f3, f4, f5, f6, f7;
    unsigned char pad1[0x40 - 0x30];
    float g0, g1, g2, g3, g4, g5, g6, g7;
    unsigned char pad2[0x1B0 - 0x60];
    int unk1B0;
};

extern "C" void fn_802DF700(int a, void* list, int count, void* base) {
    void* ptr;
    char** pp = (char**)list;
    int i = 0;
    while (i < count) {
        Entry* e = (Entry*)pp[i];
        Entry* t = (Entry*)((char*)base + e->unk1B0);
        t->g0 = t->f0;
        t->g1 = t->f1;
        t->g2 = t->f2;
        t->g3 = t->f3;
        t->g4 = t->f4;
        t->g5 = t->f5;
        t->g6 = t->f6;
        t->g7 = t->f7;
        ptr = (char*)e + 0xA0;
        fn_802E7554(a, t, &ptr, 1, 0, ptr);
        ++i;
    }
}
