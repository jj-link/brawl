#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern char lbl_80529AC8[];
extern u8 fn_80247B1C(void);
extern void fn_80232780(void *);
extern void *memset(void *, int, unsigned long);

void fn_80235D60(void) {
    u8 status;
    u32 i;

    status = 0;
    if (fn_80247B1C() != 0) {
        status = 6;
    }
    for (i = 0; i < 16; i++) {
        fn_80232780(lbl_80529AC8 + (u8)i * 0x20 + 0x14);
    }
    fn_80232780(lbl_80529AC8 + 0x228);
    (*(void (**)(int, u8 *))(lbl_80529AC8 + 0x224))(1, &status);
    memset(lbl_80529AC8, 0, 0x230);
}
