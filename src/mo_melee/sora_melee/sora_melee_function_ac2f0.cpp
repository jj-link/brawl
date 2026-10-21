#pragma force_active on
typedef unsigned int u32;

struct Data {
    u32 pad[2];
    u32 : 6;
    u32 field : 6;
    u32 : 20;
};

extern "C" void fn_27_AC2F0(Data* self, u32 value) {
    self->field = value;
}
