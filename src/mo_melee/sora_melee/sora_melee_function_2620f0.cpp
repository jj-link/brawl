#pragma force_active on

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);

struct Vec3 {
    float x, y, z;
};

extern "C" void fn_27_2620F0(void* self) {
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
            Vec3* src = *(Vec3**)(s + 0x150);
            if (src != 0) {
                *(Vec3*)(*(unsigned char**)(p + 4) + 8) = *src;
            }
        }
    }
}
