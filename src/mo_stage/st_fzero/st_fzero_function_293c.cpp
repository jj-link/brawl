#pragma force_active on

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);

struct Vec3f { float x, y, z; };

extern "C" void fn_61_293C(void* self) {
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
            unsigned char* base = *(unsigned char**)(s + 0x160);
            if (base) {
                unsigned char* src = base + (unsigned int)*(unsigned char*)(s + 0x164) * 0x30;
                float z = *(float*)(src + 0x2c);
                float y = *(float*)(src + 0x1c);
                float x = *(float*)(src + 0x0c);
                Vec3f tmp;
                tmp.x = x;
                tmp.y = y;
                tmp.z = z;
                *(Vec3f*)(*(unsigned int**)(p + 4) + 2) = tmp;
            }
        }
    }
}
