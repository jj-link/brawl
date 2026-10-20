#pragma force_active on
typedef int s32;
typedef float f32;

extern "C" void* fn_27_36028(void*, s32, s32);
extern "C" void fn_27_4AFE4(void*, void*, void*, f32);

struct Inner {
    void* pad0;
    void* data;
};

struct Mid {
    char pad[0xd8];
    Inner* inner;
};

class Target {
public:
    virtual void v0();
    virtual void* v1(s32 arg);
};

struct MyClass {
    char pad[0x28];
    Mid* mid;
    Target* target;
    char pad2[4];
    f32 f;
    char pad3[0x88];
    char field_c0[4];
};

extern "C" void fn_27_4BC88(MyClass* self, s32 arg) {
    void* innerData = self->mid->inner->data;
    void* result = self->target->v1(arg);
    void* r = fn_27_36028(self->field_c0, arg, 0);
    fn_27_4AFE4(result, innerData, r, self->f);
}
