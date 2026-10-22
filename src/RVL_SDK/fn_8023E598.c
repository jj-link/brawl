#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern s32 fn_8022EFF8(s32);
extern void fn_802319E4(s32, void *);
extern void fn_80239A24(s32);
extern void fn_80244C78(s32, s32, s32);
extern void fn_80244CD8(s32, s32, s32);
extern void fn_80245778(s32, s32, s32, s32, u16, u16, u8, u16);
extern void fn_80245860(s32, s32, s32);
extern char lbl_80529CF8[];
extern char lbl_804811C8[];

typedef struct Blk {
    s32 w0;
    s32 w1;
    s32 w2;
    s32 w3;
} Blk;

#define U8AT(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U16AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S32AT(p, o) (*(s32 *)((u8 *)(p) + (o)))

void fn_8023E598(u32 a, s32 b, s32 c, Blk *d)
{
    u8 *u;
    s32 h;
    s32 p4;
    s32 p5;
    s32 t;
    u16 v;

    u = 0;
    h = fn_8022EFF8(2);
    if (h == 0) {
        if ((u8)lbl_80529CF8[0x27C0] >= 1) {
            fn_802319E4(0xD0000, lbl_804811C8);
        }
    } else {
        if (a < 3) {
            u = (u8 *)(lbl_80529CF8 + 0x1854 + a * 0x34);
        }
        if (b != 0) {
            if (u != 0) {
                U16AT(u, 8) = (U16AT(u, 8) - 2) == 0;
            }
            if ((u8)lbl_80529CF8[0x1908] == 0) {
                fn_80244CD8(h, c, b);
                return;
            }
            fn_80245860(h, c, b);
            return;
        }
        fn_80239A24(1);
        U16AT(u, 8) = 3;
        if (((u8)lbl_80529CF8[0x1908] != 0) && (U8AT(u, 0x2E) == 2)) {
            if (d != 0) {
                *(Blk *)(u + 0x14) = *d;
            }
            p4 = U16AT(lbl_80529CF8, 0x1904);
            U16AT(u, 0x20) = p4;
            p5 = U16AT(lbl_80529CF8, 0x656);
            t = p4 & p5;
            v = t & 0x3F;
            if ((t & 0x38) == 0) {
                v |= 8;
            }
            if ((u8)lbl_80529CF8[0x636] >= 3) {
                v |= (p4 | p5) & 0x3C0;
            }
            fn_80245778(h, c, S32AT(u, 0x14), S32AT(u, 0x18), U16AT(u, 0x1C), U16AT(u, 0x1E), U8AT(u, 0x22), v);
            U16AT(u, 0x20) = v;
            return;
        }
        fn_80244C78(h, c, 0);
    }
}
