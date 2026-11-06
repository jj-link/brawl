#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 w0;
    u32 w1;
    u16 h;
} Buf;

extern u8 fn_8023D97C(int, void *, void *);
extern char lbl_8052C870[];

int fn_802471C8(void *arg0) {
    Buf buf;
    u8 sp8;

    buf.w0 = 0;
    buf.w1 = 0;
    buf.h = 0;
    sp8 = 0;

    if (*(u8 *)(lbl_8052C870 + 0x6E) != 0 ||
        (((u8 *)arg0)[8] == *(u8 *)(lbl_8052C870 + 0x6A) &&
         (((u8 *)arg0)[8] == 0 ||
          (*(u16 *)(lbl_8052C870 + 0x6C) >= ((u16 *)arg0)[1] &&
           *(u16 *)(lbl_8052C870 + 0x6C) <= ((u16 *)arg0)[0])))) {
        *(u8 *)(lbl_8052C870 + 0x78) = 0xFF;
        return 1;
    }

    switch (((u8 *)arg0)[8]) {
    case 0:
        if (*(u8 *)(lbl_8052C870 + 0x6A) == 2) {
            sp8 = fn_8023D97C(0x80, lbl_8052C870, &buf);
            *(u8 *)(lbl_8052C870 + 0x6E) = 1;
        } else if (*(u8 *)(lbl_8052C870 + 0x6A) == 3) {
            sp8 = fn_8023D97C(0x80, lbl_8052C870, &buf);
            *(u8 *)(lbl_8052C870 + 0x6E) = 1;
        }
        break;
    case 2:
        if (*(u8 *)(lbl_8052C870 + 0x6A) != 0) {
            fn_802471C8(&buf);
        } else {
            sp8 = fn_8023D97C(0x80, lbl_8052C870, arg0);
            *(u8 *)(lbl_8052C870 + 0x6E) = 1;
        }
        break;
    case 3:
        if (*(u8 *)(lbl_8052C870 + 0x6A) != 0) {
            fn_802471C8(&buf);
        } else {
            sp8 = fn_8023D97C(0x80, lbl_8052C870, arg0);
            *(u8 *)(lbl_8052C870 + 0x6E) = 1;
        }
        break;
    }

    if (sp8 <= 1) {
        return 1;
    }
    sp8 += 0x37;
    if (*(void **)(lbl_8052C870 + 0xC4) != 0) {
        (*(void (**)(int, int, void *))(lbl_8052C870 + 0xC4))(4, *(u8 *)(lbl_8052C870 + 0x6F), &sp8);
    }
    return 0;
}
