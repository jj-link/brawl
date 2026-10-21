#pragma force_active on
typedef unsigned char u8;

extern "C" int fn_80191B9C(u8** self, unsigned int idx, u8* out) {
    u8* e = *self + (idx & 1) * 0x14;
    out[0] = e[4];
    out[1] = e[5];
    out[2] = e[6];
    out[3] = e[7];
    return 1;
}
