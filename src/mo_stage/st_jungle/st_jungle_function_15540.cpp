#pragma force_active on
extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);

extern "C" void fn_51_15540(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char* p = s + 0xd0;
    if (p != 0) {
        unsigned char* a = *(unsigned char**)(s + 0x44);
        unsigned char* m = *(unsigned char**)a;
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
                float* dst;
                float* src = *(float**)(s + 0x158);
                if (src != 0) {
                    dst = *(float**)(p + 4);
                    ((float*)((unsigned char*)dst + 0x8))[0] = src[0];
                    ((float*)((unsigned char*)dst + 0xc))[0] = src[1];
                    ((float*)((unsigned char*)dst + 0x10))[0] = src[2];
                }
            }
        }
    }
}
