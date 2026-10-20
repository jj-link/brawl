#pragma force_active on
typedef unsigned int u32;

struct FlagHolder {
    u32 unk0;
    u32 unk4;
    u32 a : 2;
    u32 f : 2;
    u32 low : 28;
};

extern "C" {
void fn_27_198E94(FlagHolder* self, u32 v) {
    self->f = v;
}
}
