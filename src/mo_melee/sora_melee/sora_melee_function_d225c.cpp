#pragma force_active on
typedef unsigned int u32;

struct Data {
    u32 unused[2];
    u32 : 4;
    u32 field : 4;
    u32 : 24;
};

extern "C" void fn_27_D225C(Data* self, u32 value)
{
    self->field = value;
}
