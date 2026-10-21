#pragma force_active on
extern "C" void fn_8015E7C4(void*);
extern "C" unsigned char lbl_80497DA4[0x28];
extern "C" int lbl_805A0170;
extern "C" void free__13gfHeapManagerFPv(void*);

extern "C" int fn_8006CA64(void) {
    fn_8015E7C4(lbl_80497DA4);
    if (lbl_805A0170 != 0) {
        free__13gfHeapManagerFPv((void*)lbl_805A0170);
        lbl_805A0170 = 0;
    }
    return 1;
}
