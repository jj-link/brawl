#pragma force_active on
typedef unsigned int u32;

struct Obj {
    char pad[8];
    u32 hi : 6;
    u32 lo : 26;
};

extern "C" {
void fn_27_1CFA64(Obj* self, u32 v) {
    self->hi = v;
}
}
