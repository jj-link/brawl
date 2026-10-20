#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct FnObj {
    char pad0[4];
    void* m4;
    char pad1[0x30 - 8];
    float m30;
    u8 m34;
};

extern "C" {
s32 fn_80136160(void* p, int n);
float* fn_27_227F8C(u8* p, s32 n);
extern u8* lbl_27_bss_5668;

void fn_27_2EE20(FnObj* p) {
    s32 r = fn_80136160(p->m4, 3);
    p->m34 = r;
    u8* base = lbl_27_bss_5668;
    float* s = fn_27_227F8C(base + 0xf8, r);
    p->m30 = s[1];
}
}
