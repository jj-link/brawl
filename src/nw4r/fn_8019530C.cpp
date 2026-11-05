#pragma force_active on
extern "C" void fn_8019459C(void*, void*, void*, void*, void*);
extern const float lbl_805A31F0;
extern const float lbl_805A31F4;

extern "C" void fn_8019530C(void* arg0, void* arg1, void* arg2) {
    char* p = (char*)arg0;
    float one = lbl_805A31F4;
    *(float*)(p + 4) = one;
    *(float*)(p + 8) = one;
    *(float*)(p + 12) = one;
    fn_8019459C(p + 0x1C, p + 0x10, arg1, arg2, (char*)arg2 + 8);
    *(unsigned int*)p |= 0x80000000;
    float zero = lbl_805A31F0;
    *(float*)(p + 0x28) = zero;
    *(float*)(p + 0x38) = zero;
    *(float*)(p + 0x48) = zero;
}
