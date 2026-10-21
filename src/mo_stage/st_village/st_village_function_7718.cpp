#pragma force_active on
extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);

extern "C" void fn_70_7718(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char* p = s + 0xD0;
    if (p != 0) {
        unsigned char* a = *(unsigned char**)(s + 0x44);
        unsigned char* m = *(unsigned char**)a;
        if (m != 0) {
            if (*(unsigned int*)(m + 0x11c) == 0) {
                *(unsigned int*)(p + 0xc) = 0;
                **(unsigned int**)(p + 0x4) = *(unsigned int*)(s + 0xc4);
                *(unsigned char**)(m + 0x11c) = p;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
                *(unsigned short*)(m + 0x122) = (unsigned short)**(unsigned int**)(p + 0x4);
            }
            switch (*(unsigned char*)(s + 0x150)) {
                case 9: {
                    unsigned char* q = *(unsigned char**)(p + 0x4);
                    *(unsigned int*)(p + 0x8) = 1;
                    *(float*)(q + 0x8) = *(float*)(s + 0x1d0);
                    *(float*)(q + 0xc) = *(float*)(s + 0x1d4);
                    *(float*)(q + 0x10) = *(float*)(s + 0x1d8);
                    break;
                }
                default:
                    *(unsigned int*)(p + 0x8) = 0;
                    break;
            }
        }
    }
}
