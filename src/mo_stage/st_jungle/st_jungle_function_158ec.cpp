#pragma force_active on

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);

extern "C" void fn_51_158EC(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char* p = s + 0xd0;
    if (p != 0) {
        unsigned char* a = *(unsigned char**)(s + 0x44);
        unsigned char* m = *(unsigned char**)a;
        if (m != 0) {
            *(unsigned int*)(p + 0xc) = 1;
            unsigned int v = *(unsigned int*)(s + 0xc4);
            *(unsigned int*)(*(unsigned char**)(p + 4) + 0x80) = v;
            *(unsigned char**)(m + 0x11c) = p;
            EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
            *(short*)(m + 0x122) = (short)*(unsigned int*)(*(unsigned char**)(p + 4) + 0x80);
            {
                unsigned char* dst;
                float* src = *(float**)(s + 0x1a0);
                if (src != 0) {
                    dst = *(unsigned char**)(p + 4);
                    *(float*)(dst + 0x88) = src[0];
                    *(float*)(dst + 0x8c) = src[1];
                    *(float*)(dst + 0x90) = src[2];
                }
            }
        }
    }
}
