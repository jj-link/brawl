#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_93_rodata_C;
extern "C" const float lbl_93_rodata_18;

struct LinkVectorState {
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

extern "C" Vec2f* fn_93_DAEC(Vec2f* dst, const Vec2f* src);

extern "C" void fn_93_DB00(LinkVectorState* object) {
    Vec2f val1(lbl_93_rodata_C, lbl_93_rodata_C);
    fn_93_DAEC(&object->first, fn_93_DAEC(&object->second, fn_93_DAEC(&object->fourth, &val1)));

    Vec2f val2(lbl_93_rodata_18, lbl_93_rodata_18);
    fn_93_DAEC(&object->third, fn_93_DAEC(&object->fifth, &val2));

    object->flag31 = 0;
    object->flag30 = 0;
    object->flag32 = 1;
}
