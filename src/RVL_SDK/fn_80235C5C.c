#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern char lbl_80529AC8[];
extern u8 fn_80247B1C(void);
extern void fn_80232780(void *);
extern void fn_80237600(void *, int, int);
extern void *memset(void *, int, unsigned long);

void fn_80235C5C(void)
{
    u8 status;
    u32 i;

    if (*(void (**)(int, u8 *))(lbl_80529AC8 + 0x224) != 0) {
        if (*(u8 *)(lbl_80529AC8 + 0x22D) == 0) {
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
        } else {
            *(u8 *)(lbl_80529AC8 + 0x22E) = 1;
            for (i = 0; i < 16; i++) {
                char *p = lbl_80529AC8 + (u8)i * 0x20;
                if (*(u8 *)(p + 0x2C) == 3) {
                    fn_80237600(p + 0x10, 0x1701, 0);
                }
            }
        }
    }
}
