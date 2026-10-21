#pragma force_active on
typedef unsigned int u32;

struct Object {
    u32 pad[2];
    u32 upper : 5;
    u32 field : 5;
    u32 lower : 22;
};

extern "C" void fn_27_CBCE0(Object* self, u32 value) {
    self->field = value;
}
