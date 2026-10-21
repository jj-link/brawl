#pragma force_active on
typedef unsigned int u32;

struct Object {
    u32 pad[2];
    u32 upper : 10;
    u32 field : 5;
    u32 lower : 17;
};

extern "C" void fn_27_B04C8(Object* self, u32 value) {
    self->field = value;
}
