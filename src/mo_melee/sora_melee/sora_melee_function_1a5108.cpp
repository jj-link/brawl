#pragma force_active on
typedef unsigned int u32;

struct FlagHolder {
    char pad[8];
    u32 a : 5;
    u32 f : 5;
    u32 b : 22;
};

extern "C" void fn_27_1A5108(FlagHolder* self, u32 val) {
    self->f = val;
}
