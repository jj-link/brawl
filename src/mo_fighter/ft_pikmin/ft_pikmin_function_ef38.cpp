#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_113_rodata_C;
extern "C" const float lbl_113_rodata_14;
extern "C" Vec2f* fn_113_BC00(Vec2f* dst, const Vec2f* src);

struct PikminVectorState {
    u32 header[2];
    Vec2f first;
    Vec2f second;
    Vec2f third;
    Vec2f fourth;
    Vec2f fifth;
    u8 flag30;
    u8 flag31;
    u8 flag32;
};

extern "C" void fn_113_EF38(PikminVectorState* object) {
    Vec2f zero(lbl_113_rodata_C, lbl_113_rodata_C);
    fn_113_BC00(&object->first, fn_113_BC00(&object->second, fn_113_BC00(&object->fourth, &zero)));
    Vec2f initial(lbl_113_rodata_14, lbl_113_rodata_14);
    fn_113_BC00(&object->third, fn_113_BC00(&object->fifth, &initial));
    object->flag31 = 0;
    object->flag30 = 0;
    object->flag32 = 1;
}
