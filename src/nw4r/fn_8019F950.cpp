#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
struct Buf { u8 b0; u8 b1; u8 b2; u8 b3; u32 idx; u32 flags; };
extern "C" {
extern Buf lbl_804A44C0;
extern const u8 lbl_805A3318[4];
extern u8 lbl_805A0538;
void fn_80190AA8(int* p, int flag);
void fn_8019F950(int* p) {
    if (*p == 0) return;
    if ((lbl_804A44C0.flags & 4) && (lbl_804A44C0.flags & 3) == 2) {
        u32 idx = lbl_804A44C0.idx;
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
        lbl_804A44C0.flags = lbl_804A44C0.flags | 1;
    }
    u8 c = lbl_805A0538;
    lbl_805A0538 = 0;
    fn_80190AA8(p, c);
}
}