#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
struct Buf { u8 b0; u8 b1; u8 b2; u8 b3; u32 idx; u32 flags; };
struct Handle { u32 v; };
extern "C" {
extern Buf lbl_804A44C0;
extern const u8 lbl_805A3318[4];
extern u8 lbl_805A0538;
void fn_8019163C(Handle*, int, int);
int fn_80191670(Handle*, int, void*);
void fn_8019DBBC(int, void*);
}
struct Data { u32 flags; u32 m[3][12]; };
class Object_vptr_0 { public: virtual void slot0(Data*); };
inline void helper(Handle p) {
    if (p.v) {
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
        fn_8019163C(&p, lbl_804A44C0.b3, c);
    }
}
inline void helper2(u32 v, Object_vptr_0* arg1) {
    Data d;
    d.flags = 0;
    Handle p;
    p.v = v;
    if (fn_80191670(&p, 1, d.m[0])) d.flags |= 1;
    if (fn_80191670(&p, 2, d.m[1])) d.flags |= 2;
    if (fn_80191670(&p, 3, d.m[2])) d.flags |= 4;
    arg1->slot0(&d);
    if (d.flags & 1) fn_8019DBBC(0, d.m[0]);
    if (d.flags & 2) fn_8019DBBC(3, d.m[1]);
    if (d.flags & 4) fn_8019DBBC(6, d.m[2]);
}
extern "C" void fn_8019FB60(const Handle* arg0, Object_vptr_0* arg1) {
    if (arg0->v) {
        helper(*arg0);
        helper2(arg0->v, arg1);
    }
}
