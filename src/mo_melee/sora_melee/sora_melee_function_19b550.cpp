#pragma force_active on
typedef unsigned int u32;

struct Fn19Bits {
    u32 unk_pad[2];
    u32 unk0 : 6;
    u32 field : 6;
    u32 unk1 : 20;
};

extern "C" void fn_27_19B550(Fn19Bits *obj, u32 val)
{
    obj->field = val;
}
