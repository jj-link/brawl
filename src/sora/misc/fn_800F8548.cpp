#pragma force_active on

extern "C" {
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
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
    Object* f10;
    void* f14;
};

extern "C" Self* fn_800F8548(Self* self, int flag) {
    if (self) {
        if (&self->f14) {
            if (self->f14) Destroy__Q34nw4r3g3d6G3dObjFv(self->f14);
            self->f14 = 0;
        }
        if (&self->f10) {
            delete self->f10;
        }
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
