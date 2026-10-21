#pragma force_active on
extern "C" void fn_8015E7C4(void*);
extern "C" void free__13gfHeapManagerFPv(void*);
extern "C" char lbl_80497E1C[];
extern "C" void* lbl_805A0184;

extern "C" int fn_8006C6DC(void) {
    fn_8015E7C4(lbl_80497E1C);
    if (lbl_805A0184 != 0) {
        free__13gfHeapManagerFPv(lbl_805A0184);
        lbl_805A0184 = 0;
    }
    return 1;
}
