#include <types.h>
#pragma force_active on
extern "C" {
void fn_8019092C(void** self, unsigned char flag);
void fn_8019DB4C(int idx, unsigned short a, int b, int c, unsigned short d, int e, int f, void* p);
extern const u8 lbl_805A3318[4];
extern unsigned int lbl_805A0544;
extern unsigned char lbl_805A0538;
struct Cfg { unsigned char b0, b1, b2, b3; unsigned int w4, w8; };
extern Cfg lbl_804A44C0;
struct Tbl { unsigned int w0; unsigned char pad4[0x0C]; unsigned int w10, w14; unsigned char pad18[0x4C]; unsigned int w64, w68; };
extern Tbl lbl_804A44CC;
void fn_8019F740(void** arg0) {
    unsigned char i;
    unsigned char r29;
    void* p = *arg0;
    int r0;
    if (p == 0) return;
    if ((unsigned int)p == lbl_805A0544) { r0 = 1; } else { lbl_805A0544 = (unsigned int)p; r0 = 0; }
    if (r0 != 0) return;
    if ((lbl_804A44C0.w8 & 4) && ((lbl_804A44C0.w8 & 3) == 2)) {
        u32 idx = lbl_804A44C0.w4;
        u8* fifo = (u8*)0xCC008000;
        *fifo++ = 0x61;
        *(u32*)(fifo - 1) = 0xFE07FC3F;
        u32 tbl = lbl_805A3318[idx];
        *--fifo = 0x61;
        u32 a = tbl << 14;
        u32 v2 = lbl_804A44C0.b2;
        u32 v1 = lbl_804A44C0.b1;
        u32 v3 = lbl_804A44C0.b3;
        u32 v0 = lbl_804A44C0.b0;
        u32 c3 = v3 << 16;
        u32 ca = c3 | a;
        u32 c2 = (v2 - 1) << 10;
        u32 c1 = v1 << 4;
        u32 b = c2 | (v0 | c1);
        *(u32*)fifo = ca | b;
        lbl_804A44C0.w8 = lbl_804A44C0.w8 | 1;
    }
    unsigned char t = lbl_805A0538;
    lbl_805A0538 = 0;
    fn_8019092C(arg0, t);
    unsigned int* q = (unsigned int*)*arg0;
    if (!(lbl_804A44CC.w0 & 2) || q[4] != lbl_804A44CC.w64 || q[5] != lbl_804A44CC.w68) {
        lbl_804A44CC.w64 = q[4];
        lbl_804A44CC.w68 = q[5];
        lbl_804A44CC.w0 = (lbl_804A44CC.w0 | 2) & ~1u;
    }
    r29 = lbl_804A44C0.b0;
    if ((lbl_804A44CC.w0 & 2) && !(lbl_804A44CC.w0 & 1) && r29 != 0) {
        for (i = 0; i < r29; i++) {
            unsigned char k = ((unsigned char*)&lbl_804A44CC)[0x64 + i];
            if (k != 0xFF) {
                unsigned char* base = (unsigned char*)&lbl_804A44CC;
                unsigned char* p10 = base + (i << 3);
                unsigned short a = *(unsigned short*)(base + (k << 2) + 4);
                *(unsigned short*)(p10 + 0x24) = a;
                unsigned char k2 = ((unsigned char*)&lbl_804A44CC)[0x64 + i];
                unsigned short b = *(unsigned short*)(base + (k2 << 2) + 6);
                *(unsigned short*)(p10 + 0x26) = b;
                fn_8019DB4C(i, a, 0, 0, b, 0, 0, p10);
            }
        }
        lbl_804A44CC.w0 |= 1;
    }
}
}