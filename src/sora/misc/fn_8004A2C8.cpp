#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct E {
    u8 f[12];
};
struct F {
    u8 f[0x21];
};

struct S {
    E a[4];
    F b[4];
    u8 pad;
    u8 c[8];
};

static inline void cp(E* d, const u8* src) {
    d->f[0] = src[0];
    d->f[1] = src[1];
    d->f[2] = src[2];
    d->f[3] = src[3];
    d->f[4] = src[4];
    d->f[5] = src[5];
    d->f[6] = src[6];
    d->f[7] = src[7];
    d->f[8] = src[8];
    d->f[9] = src[9];
    d->f[10] = src[10];
    d->f[11] = src[11];
}

extern "C" void fn_8004A2C8(S* s, int idx, u32 n, u8* src) {
    s->c[idx] = n;
    if (n < 4) {
        cp(&s->a[n], src);
        return;
    }
    if (n < 8) {
        F& d = s->b[n - 4];
        d.f[0] = src[12];
        d.f[1] = src[13];
        d.f[2] = src[14];
        d.f[3] = src[15];
        d.f[4] = src[16];
        d.f[5] = src[17];
        d.f[6] = src[18];
        d.f[7] = src[19];
        d.f[8] = src[20];
        d.f[9] = src[21];
        d.f[10] = src[22];
        d.f[11] = src[23];
        d.f[12] = src[24];
        d.f[13] = src[25];
        d.f[14] = src[26];
        d.f[15] = src[27];
        d.f[16] = src[28];
        d.f[17] = src[29];
        d.f[18] = src[30];
        d.f[19] = src[31];
        d.f[20] = src[32];
        d.f[21] = src[33];
        d.f[22] = src[34];
        d.f[23] = src[35];
        d.f[24] = src[36];
        d.f[25] = src[37];
        d.f[26] = src[38];
        d.f[27] = src[39];
        d.f[28] = src[40];
        d.f[29] = src[41];
        d.f[30] = src[42];
        d.f[31] = src[43];
        d.f[32] = src[44];
    }
}
