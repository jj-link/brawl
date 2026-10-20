#pragma force_active on
extern "C" int lbl_27_bss_3210;

extern "C" int fn_27_147C38() {
    int* p = *(int**)((char*)&lbl_27_bss_3210 + 0x3c);
    return *(int*)((char*)p + 0x134);
}
