#pragma force_active on
extern unsigned char lbl_80536620[];
extern void* lbl_805A1154;

void fn_80390014(void* p);
void fn_803906AC(void* p);
void fn_803911BC(void* p);
void fn_803908FC(void* p);
void fn_803930A0(void* p);

void* fn_803974FC(void) {
    if (lbl_805A1154 == 0) {
        lbl_805A1154 = lbl_80536620;
        fn_80390014(lbl_80536620);
        fn_803906AC(lbl_80536620 + 0x800);
        fn_803911BC(lbl_80536620 + 0x808);
        fn_803908FC(lbl_80536620 + 0x80C);
        fn_803930A0(lbl_80536620 + 0x840);
    }
    return lbl_805A1154;
}
