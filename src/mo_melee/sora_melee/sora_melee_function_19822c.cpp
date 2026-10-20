#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_19822C_obj {
    char pad[8];
    u32 field;
};

extern "C" s32 fn_27_19822C(fn_27_19822C_obj *p)
{
    return (s32)(((p->field >> 19) & 0x1F) << 27) >> 28;
}
