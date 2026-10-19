#pragma force_active on
extern "C" extern const float lbl_40_rodata_2FC;

struct Obj {
    char pad0[0x60];
    float a;
    float b;
    float c;
    char pad1[0x08];
    unsigned int d;
};

extern "C" void fn_40_1E2D4(Obj* p) {
    unsigned int v = p->d;
    float z = lbl_40_rodata_2FC;
    p->a = z;
    p->b = z;
    p->c = z;
    p->d = v & ~0x1Fu;
}
