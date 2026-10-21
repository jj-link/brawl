#pragma force_active on

struct Vec3f {
    float x, y, z;
    Vec3f() {}
    Vec3f(const Vec3f& v) : x(v.x), y(v.y), z(v.z) {}
    Vec3f& operator=(const Vec3f& v) {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }
};

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);
extern "C" void getRot__9grGimmickFv(Vec3f* out, void* self);

extern "C" void fn_74_B11C(void* self, int index) {
    char* p = (char*)self;
    if (*(int*)(p + 0xd8) > 0) {
        void** models = (void**)*(void**)(p + 0x44);
        void* model = models[index];
        if (model != 0) {
            char* mp = (char*)model;
            if (*(int*)(mp + 0x11c) == 0) {
                *(unsigned int*)(p + 0xdc) = 0;
                *(unsigned int*)(mp + 0x11c) = (unsigned int)self + 0xd0;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
                *(unsigned short*)(mp + 0x122) = *(unsigned int*)(*(unsigned int**)(p + 0xd4));
            }
            Vec3f rot;
            Vec3f temp;
            getRot__9grGimmickFv(&temp, self);
            rot = temp;
            Vec3f* v = (Vec3f*)((char*)(*(unsigned int**)(p + 0xd4)) + 0x38);
            *v = rot;
        }
    }
}
