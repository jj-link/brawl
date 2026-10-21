#pragma force_active on
extern "C" {
typedef struct {
    unsigned int a;
    unsigned char b;
    unsigned char c[11];
} Entry804556D8;

extern const Entry804556D8 lbl_804556D8[];

unsigned char fn_800AF6F0(int idx) {
    return lbl_804556D8[idx].b;
}
}
