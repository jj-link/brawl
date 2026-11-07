#include <types.h>
#include <so/so_array.h>
#include <so/so_common_data_accesser.h>
#pragma force_active on

struct Self {
    soArrayFixed<soMotionData>* array;
    s32 offset;
};

extern const soMotionData lbl_27_rodata_380;

extern "C" const soMotionData& fn_27_20FE4(
    Self* self, s32 index, u32 mode)
{
    if (index == -1) {
        return lbl_27_rodata_380;
    }
    if (mode == 1) {
        return self->array->at(index + self->offset);
    }
    return self->array->at(index);
}
