#pragma force_active on

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void*, unsigned long);

struct Vec {
    float x, y, z;
};

extern "C" void fn_73_E84C(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char* p = s + 0xd0;
    if (p != 0) {
        unsigned char** a = *(unsigned char***)(s + 0x44);
        unsigned char* m = a[*(unsigned int*)(s + 0xc0)];
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

            int index;
            switch (*(unsigned char*)(s + 0x168)) {
                case 4: index = 0; break;
                case 5: index = 1; break;
                case 6: index = 2; break;
                case 7: index = 3; break;
                default: return;
            }

            Vec* src = *(Vec**)(s + 0x158) + index;
            Vec* dst = (Vec*)(*(unsigned char**)(p + 4) + 8);
            *dst = *src;
        }
    }
}
