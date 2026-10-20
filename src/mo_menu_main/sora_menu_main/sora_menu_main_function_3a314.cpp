#pragma force_active on
extern "C" void __dl__FPv(void*);

struct Object {
    unsigned char reserved[0x5C];
    virtual ~Object();
};

struct Wrapper {
    Object* object;
};

extern "C" Wrapper* fn_2_3A314(Wrapper* self, int deleting) {
    if (self) {
        delete self->object;
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
