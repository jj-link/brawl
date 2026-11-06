#pragma force_active on

typedef unsigned int u32;

typedef struct {
    float f[12];
    char a;
    char b;
    char pad[0x9E];
} S __attribute__((aligned(16)));

extern void fn_802821DC(int, void *);

int fn_80284F2C(float *out, int arg1) {
    S s;
    fn_802821DC(arg1, &s);
    out[0] = s.f[0];
    out[1] = s.f[1];
    out[2] = s.f[2];
    out[3] = s.f[3];
    out[4] = s.f[4];
    out[5] = s.f[5];
    out[6] = s.f[6];
    out[7] = s.f[7];
    out[8] = s.f[8];
    out[9] = s.f[9];
    out[10] = s.f[10];
    out[11] = s.f[11];
    return (__cntlzw((u32)(-s.b | s.b) >> 31U) << 19) & 0xFF000000;
}
