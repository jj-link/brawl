#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef void (*Callback)(u8 *, u32, u32);

typedef struct {
    u8 pad[0x27B0];
    Callback callback;
    u8 pad2[0xC];
    u8 level;
    u8 pad3[7];
} State;

extern State lbl_80529CF8;
extern const u8 lbl_805A3A98;
extern const u8 lbl_805A3A99;
extern const u8 lbl_805A3A9A;
extern const u8 lbl_805A3A9B;
extern const u8 lbl_805A3A9C;
extern const u8 lbl_805A3A9D;
extern const char lbl_80481B08[];

extern u8 *fn_8023A038(u32);
extern void fn_80231A14(u32, const char *, u32, int);

void fn_80240D54(u32 arg0, u32 arg1, u32 arg2)
{
    u8 *p = fn_8023A038(arg0);
    u8 addr[6];

    addr[0] = lbl_805A3A98;
    addr[1] = lbl_805A3A99;
    addr[2] = lbl_805A3A9A;
    addr[3] = lbl_805A3A9B;
    addr[4] = lbl_805A3A9C;
    addr[5] = lbl_805A3A9D;

    if (lbl_80529CF8.level >= 4) {
        fn_80231A14(0xD0003, lbl_80481B08, arg1, p ? p[0x7F] : 0);
    }

    if (lbl_80529CF8.callback) {
        if (p == 0) {
            lbl_80529CF8.callback(addr, arg1, arg2);
        } else {
            lbl_80529CF8.callback(p + 0x1C, arg1, arg2);
        }
    }
}
