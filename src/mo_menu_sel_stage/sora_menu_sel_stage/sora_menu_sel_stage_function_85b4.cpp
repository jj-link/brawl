#pragma force_active on
extern "C" {
typedef struct {
    unsigned int a;
    unsigned char b;
    unsigned char c[3];
} SelEntry;

extern const SelEntry lbl_11_rodata_280[];

unsigned char fn_11_85B4(int idx) {
    return lbl_11_rodata_280[idx].b;
}
}
