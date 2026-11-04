#pragma force_active on

extern "C" {
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void __destroy_arr(void*, void (*)(void*, int), int, int);
void fn_40_437DC(void*, int);
void __dl__FPv(void*);
}

class Object {
    char pad[0x5C];
public:
    virtual ~Object();
};

struct Self {
    Object* f0;
    Object* f4;
    Object* f8;
    Object* fC;
    char pad10[0xA8];
    void* fB8;
    void* fBC;
};

extern "C" Self* fn_40_438BC(Self* self, int flag) {
    if (self) {
        if (&self->fBC) {
            if (self->fBC) Destroy__Q34nw4r3g3d6G3dObjFv(self->fBC);
            self->fBC = 0;
        }
        if (&self->fB8) {
            if (self->fB8) Destroy__Q34nw4r3g3d6G3dObjFv(self->fB8);
            self->fB8 = 0;
        }
        __destroy_arr((char*)self + 0x10, fn_40_437DC, 4, 0x2A);
        if (&self->fC) {
            delete self->fC;
        }
        if (&self->f8) {
            delete self->f8;
        }
        if (&self->f4) {
            delete self->f4;
        }
        if (&self->f0) {
            delete self->f0;
        }
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
