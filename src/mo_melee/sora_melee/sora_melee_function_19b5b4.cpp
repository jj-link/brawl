#pragma force_active on
typedef unsigned int u32;

struct FieldHolder {
    char pad[8];
    u32 a : 12;
    u32 b : 6;
    u32 c : 14;
};

extern "C" void fn_27_19B5B4(FieldHolder* self, u32 v) {
    self->b = v;
}
