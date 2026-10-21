#pragma force_active on

extern "C" void fn_8015E7C4(void*);
extern "C" void* lbl_805A0174;
extern "C" int lbl_80497D54[];
extern "C" void free__13gfHeapManagerFPv(void*);

extern "C" int fn_8006C90C(void) {
    fn_8015E7C4(&lbl_80497D54);
    if (lbl_805A0174 != 0) {
        free__13gfHeapManagerFPv(lbl_805A0174);
        lbl_805A0174 = 0;
    }
    return 1;
}
