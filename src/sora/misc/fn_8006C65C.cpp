#pragma force_active on
extern "C" void fn_8015E7C4(void*);
extern "C" void free__13gfHeapManagerFPv(void*);
extern "C" char lbl_80497DF4[];
extern "C" void* lbl_805A0180;

extern "C" int fn_8006C65C(void) {
    fn_8015E7C4(lbl_80497DF4);
    if (lbl_805A0180 != 0) {
        free__13gfHeapManagerFPv(lbl_805A0180);
        lbl_805A0180 = 0;
    }
    return 1;
}
