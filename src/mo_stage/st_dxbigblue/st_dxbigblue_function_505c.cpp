#pragma force_active on

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);

extern "C" void fn_81_505C(void* self) {
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
            unsigned char* d;
            unsigned char* sv = *(unsigned char**)(s + 0x164);
            if (sv != 0) {
                d = *(unsigned char**)(p + 4);
                *(float*)(d + 0x8) = *(float*)(sv + 0x4);
                *(float*)(d + 0xc) = *(float*)(sv + 0x8);
                *(float*)(d + 0x10) = *(float*)(sv + 0xc);
                unsigned char* d2 = *(unsigned char**)(p + 4);
                unsigned char* sv2 = *(unsigned char**)(s + 0x164);
                *(float*)(d2 + 0x14) = *(float*)(sv2 + 0x1c);
                *(float*)(d2 + 0x18) = *(float*)(sv2 + 0x20);
                *(float*)(d2 + 0x1c) = *(float*)(sv2 + 0x24);
            }
        }
    }
}
