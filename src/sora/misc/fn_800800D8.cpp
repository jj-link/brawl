#pragma force_active on
struct fn_800800D8_Obj {
    char pad[0x8];
    int m08;
    int m0C;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
};

extern "C" void fn_800800D8(fn_800800D8_Obj* p) {
    p->m08 = 0;
    p->m0C = 0;
    p->m10 = (int)0x80000000;
    p->m14 = 0;
    p->m18 = 0;
    p->m1C = (int)0x80000000;
    p->m20 = 0;
    p->m24 = 0;
    p->m28 = (int)0x80000000;
    p->m30 = 0;
    p->m34 = 0;
    p->m38 = 0;
    p->m3C = 0;
}
