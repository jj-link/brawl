#pragma force_active on
typedef unsigned int u32;

extern "C" unsigned char lbl_27_data_33958[];

struct fn_27_1A6CE8_object
{
    u32 field0;
    u32 field4;
    u32 field8;
};

extern "C" void fn_27_1A6CE8(fn_27_1A6CE8_object *object)
{
    u32 value = object->field8;

    object->field0 = (u32)lbl_27_data_33958;
    object->field4 = (u32)(lbl_27_data_33958 + 0x48);
    object->field8 = value & 1;
}
