#pragma force_active on
extern unsigned char lbl_80529994[];

extern void fn_80234510(void);
extern void fn_8023457C(void);
extern void fn_802394BC(void *, void (*)(void));
extern void fn_802395F8(void *, void (*)(void));
extern void fn_802324FC(void *, int, int);

void fn_80234110(void)
{
    unsigned char i;

    if (lbl_80529994[0x6C] & 1) {
        for (i = 0; i < lbl_80529994[0x4D]; i++) {
            fn_802394BC(lbl_80529994 + i * 11, fn_80234510);
        }
    }

    if (lbl_80529994[0x6C] & 2) {
        for (i = 0; i < lbl_80529994[0x4D]; i++) {
            fn_802395F8(lbl_80529994 + i * 11, fn_8023457C);
        }
    }

    if (*(unsigned short *)(lbl_80529994 + 0x70) != 0) {
        *(void (**)(void))(lbl_80529994 + 0x5C) = fn_80234110;
        fn_802324FC(lbl_80529994 + 0x54, 0,
                   *(unsigned short *)(lbl_80529994 + 0x70) * 1000);
    }
}
