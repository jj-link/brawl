#pragma force_active on
struct Target {
    unsigned char padding[0xD4];
    void* field_D4;
};

struct Wrapper {
    Target* target;
};

struct Object {
    unsigned char padding[0x3C];
    void* vtable;
    unsigned int field_40;
    Wrapper* wrapper;
};

extern "C" {
extern unsigned char lbl_74_data_2E60[];
void fn_74_26B0(Object*, int);
void __dl__FPv(void*);

Object* fn_74_CF5C(Object* self, int deleteFlag)
{
    if (self) {
        self->vtable = lbl_74_data_2E60;
        Target* target = self->wrapper->target;
        if (target) {
            target->field_D4 = 0;
        }
        fn_74_26B0(self, 0);
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
