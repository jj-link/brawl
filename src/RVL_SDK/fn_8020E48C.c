#pragma force_active on
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

extern u8 lbl_804ED380[];
s32 fn_8020BCA8(void *a, void *b, void *c);
void fn_8020E600(void);
void fn_8020E574(s32 arg0);
void fn_8020E73C(void);

void fn_8020E48C(u32 arg0) {
    u32 var_r0;

    if (arg0 == *(u32 *)(lbl_804ED380 + lbl_804ED380[0x15A] * 4 + 0x174)) {
        *(u32 *)(lbl_804ED380 + lbl_804ED380[0x15A] * 4 + 0x17C) = arg0;
        lbl_804ED380[0x159] = 0;
        if (fn_8020BCA8(lbl_804ED380 + 8, fn_8020E574, lbl_804ED380 + 0x94) == 0) {
            return;
        }
    }
    if (lbl_804ED380[0x15A] == 0) {
        var_r0 = -0x80;
        if (arg0 != 0) {
            var_r0 = arg0;
        }
        *(u32 *)(lbl_804ED380 + 0x160) = var_r0;
    }
    *(u32 *)((u8 *)lbl_804ED380 + (s32)(*(u8 *)(lbl_804ED380 + 0x15A)) * 4 + 0x17C) = 0;
    if (lbl_804ED380[0x159] == 0 || fn_8020BCA8(lbl_804ED380 + 8, fn_8020E73C, lbl_804ED380 + 0x94) != 0) {
        fn_8020E600();
    }
}
