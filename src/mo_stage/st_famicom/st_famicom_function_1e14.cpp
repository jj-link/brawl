#pragma force_active on
extern const float lbl_68_rodata_0;
extern const float lbl_68_rodata_10;

struct FamicomState {
    float f[6];
    unsigned char b18;
    unsigned char b19;
    float f1c;
    float f20;
    unsigned char b24;
};

extern "C" void fn_68_1E14(int unused, FamicomState* p)
{
    if (p == 0) {
        return;
    }
    float z = lbl_68_rodata_0;
    p->f[0] = z;
    p->f[1] = z;
    p->f[2] = z;
    p->f[3] = z;
    p->f[4] = z;
    p->f[5] = z;
    p->b18 = 1;
    p->b19 = 0;
    p->f1c = z;
    p->f20 = lbl_68_rodata_10;
    p->b24 = 13;
}
