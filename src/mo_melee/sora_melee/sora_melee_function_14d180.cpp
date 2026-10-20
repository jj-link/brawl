#pragma force_active on
typedef int s32;

struct Obj {
    char pad[0x24];
    s32 val;
};

extern "C" void fn_27_14D180(Obj* self, s32 v) {
    self->val += v;
}
