#pragma force_active on
extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);

extern "C" void fn_49_C560(void* arg0) {
    unsigned char* s = (unsigned char*)arg0;
    unsigned char* p = s + 0xd0;
    if (p != 0) {
        unsigned long idx = *(unsigned int*)(s + 0xc0);
        unsigned char* a = *(unsigned char**)(s + 0x44);
        unsigned char* m = *(unsigned char**)(a + idx * 4);
        if (m != 0) {
            if (*(unsigned int*)(m + 0x11c) == 0) {
                *(unsigned int*)(p + 0xc) = 0;
                unsigned int* q = *(unsigned int**)(p + 4);
                *q = *(unsigned int*)(s + 0xc4);
                *(unsigned char**)(m + 0x11c) = p;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
                q = *(unsigned int**)(p + 4);
                *(short*)(m + 0x122) = (short)*q;
            }
            {
                float* dst = *(float**)(p + 4);
                dst[2] = *(float*)(s + 0x158);
                dst[3] = *(float*)(s + 0x15c);
                dst[4] = *(float*)(s + 0x160);
            }
        }
    }
}
