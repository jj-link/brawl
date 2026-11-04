#pragma force_active on

extern "C" {
void fn_8018CC44(unsigned char* p, unsigned int v);
extern float lbl_805A3198;

void fn_80191930(unsigned char** arg0, int arg1, float* arg2, int arg3) {
    int idx;
    unsigned char* base;
    unsigned int v;
    unsigned int t;
    int r29;
    unsigned char* p = *arg0;

    switch (arg1) {
    case 1:
        base = p + 0xA;
        idx = 0;
        break;
    case 2:
        base = p + 0x20;
        idx = 3;
        break;
    case 3:
        base = p + 0x2F;
        idx = 6;
        break;
    default:
        return;
    }

    r29 = arg3 + 0x11;

    v = ((int)(lbl_805A3198 * arg2[0]) & 0x7FF) | ((r29 << 22) & 0xC00000) | (((int)(lbl_805A3198 * arg2[4]) << 11) & 0x3FF800) | ((idx + 6) << 24);
    fn_8018CC44(base, v);

    t = ((int)(lbl_805A3198 * arg2[1]) & 0x7FF) | (((int)(lbl_805A3198 * arg2[5]) << 11) & 0x3FF800) | ((r29 << 20) & 0xC00000) | ((idx + 7) << 24);
    fn_8018CC44(base + 5, t);

    t = ((int)(lbl_805A3198 * arg2[2]) & 0x7FF) | (((int)(lbl_805A3198 * arg2[6]) << 11) & 0x3FF800) | ((r29 << 18) & 0xC00000) | ((idx + 8) << 24);
    fn_8018CC44(base + 0xA, t);
}
}
