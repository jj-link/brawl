#pragma force_active on
extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);
extern const float lbl_61_rodata_30;

extern "C" {
void fn_61_350C(char* self) {
    const float* f = &lbl_61_rodata_30;
    char* p = self + 0xd0;
    if (p != 0) {
        char* m = *(char**)(*(char**)(self + 0x44));
        if (m != 0) {
            if (*(int*)(m + 0x11c) == 0) {
                *(int*)(p + 0xc) = 0;
                *(int*)(*(char**)(p + 4)) = *(int*)(self + 0xc4);
                *(char**)(m + 0x11c) = p;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
                *(short*)(m + 0x122) = (short)*(int*)(*(char**)(p + 4));
            }
            {
                char* q = *(char**)(p + 4);
                float a = f[0];
                float b = f[6];
                *(float*)(q + 0x8) = a;
                float c = f[7];
                *(float*)(q + 0xc) = b;
                *(float*)(q + 0x10) = c;
            }
        }
    }
}
}
