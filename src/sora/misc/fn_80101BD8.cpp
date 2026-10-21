#pragma force_active on
extern "C" void exit__6gfTaskFv(void*);
extern "C" void* lbl_805A0310;

extern "C" void fn_80101BD8() {
    if (lbl_805A0310) {
        exit__6gfTaskFv(lbl_805A0310);
    }
    lbl_805A0310 = 0;
}
