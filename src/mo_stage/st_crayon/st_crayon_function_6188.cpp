#pragma force_active on
extern const float lbl_56_rodata_98;

struct StCrayonObj {
    char pad[0x60];
    float f60;
    float f64;
    float f68;
    char pad2[0x74 - 0x6C];
    unsigned int u74;
};

extern "C" {
void fn_56_6188(StCrayonObj* p) {
    float z = lbl_56_rodata_98;
    p->f60 = z;
    p->f64 = z;
    p->f68 = z;
    p->u74 &= ~0x1Fu;
}
}
