#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 unk0;
    u32 unk4;
    u32 hi : 3;
    u32 lo : 29;
};

extern "C" {
void fn_27_295CEC(Flags* self, u32 v)
{
    self->hi = v;
}
}
