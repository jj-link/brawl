#pragma force_active on
extern "C" int fn_41_15FD4(int, int);
extern "C" void fn_41_1EF14(void*, void*);
extern float lbl_41_rodata_C3C;

extern "C" float fn_41_161B4(void* a, int b) {
    if (b == -1) return lbl_41_rodata_C3C;
    fn_41_1EF14((void*)fn_41_15FD4((int)a, b), *(void**)((unsigned char*)a + 0x20));
}
