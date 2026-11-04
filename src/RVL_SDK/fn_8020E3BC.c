#pragma force_active on
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
extern u8 lbl_804ED380[];
s32 fn_8020AAE0(void *, u32, u32, void (*)(u32), void *);
s32 fn_8020BCA8(void *, void (*)(void), void *);
void fn_8020E48C(u32);
void fn_8020E73C(void);
void fn_8020E600(void);

void fn_8020E3BC(s32 arg0) {
    if (arg0 == 0) {
        lbl_804ED380[0x159] = 1;
        if (fn_8020AAE0(lbl_804ED380 + 8,
            *(u32 *)(lbl_804ED380 + lbl_804ED380[0x15A] * 4 + 0x16C),
            *(u32 *)(lbl_804ED380 + lbl_804ED380[0x15A] * 4 + 0x174),
            fn_8020E48C, lbl_804ED380 + 0x94) == 0) {
            return;
        }
    }
    if (lbl_804ED380[0x15A] == 0) {
        *(s32 *)(lbl_804ED380 + 0x160) = arg0;
    }
    *(s32 *)((u8 *)lbl_804ED380 + (s32)(*(u8 *)(lbl_804ED380 + 0x15A)) * 4 + 0x17C) = 0;
    if (*(u8 *)(lbl_804ED380 + 0x159) == 0 || fn_8020BCA8(lbl_804ED380 + 8, fn_8020E73C, lbl_804ED380 + 0x94) != 0) {
        fn_8020E600();
    }
}