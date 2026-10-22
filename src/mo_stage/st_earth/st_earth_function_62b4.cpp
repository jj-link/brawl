#pragma force_active on

struct Vec3f {
    float x, y, z;
};

struct Object {
    char pad0[0x184];
    Vec3f* position;
};

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);

extern "C" void fn_66_62B4(Object* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char* p = s + 0xd0;
    if (p != 0) {
        unsigned char* a = *(unsigned char**)(s + 0x44);
        unsigned char* m = *(unsigned char**)(a + 0);
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
            Vec3f* pos = self->position;
            if (pos != 0) {
                Vec3f* d = (Vec3f*)(*(unsigned char**)(p + 4) + 0x2c);
                d->x = pos->x;
                d->y = pos->y;
                d->z = pos->z;
            }
        }
    }
}
