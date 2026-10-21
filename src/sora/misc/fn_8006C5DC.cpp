#pragma force_active on
extern "C" void fn_8015E7C4(void*);
extern "C" void free__13gfHeapManagerFPv(void*);
extern "C" char lbl_80497DCC[];
extern "C" void* lbl_805A017C;

extern "C" int fn_8006C5DC() {
    fn_8015E7C4(lbl_80497DCC);
    if (lbl_805A017C != 0) {
        free__13gfHeapManagerFPv(lbl_805A017C);
        lbl_805A017C = 0;
    }
    return 1;
}
