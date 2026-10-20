#pragma force_active on
typedef unsigned int u32;

struct FnObj27 {
    char pad[0x1c];
    u32 field1c;
};

extern "C" void fn_27_22890C(FnObj27 *self)
{
    self->field1c = 0xFFFF;
}
