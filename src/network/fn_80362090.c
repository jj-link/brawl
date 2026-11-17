#include <types.h>
#pragma force_active on
struct Obj_80361A68 { char _0x00[0x14]; u32 field_14; u32 field_18; s16 field_1c; u8 buffer[0x40]; };
extern void fn_80361B7C(void*);

void fn_80362090(struct Obj_80361A68* obj) {
    if (obj->field_1c > 55) {
        obj->buffer[obj->field_1c++] = 0x80;
        while (obj->field_1c < 64) {
            obj->buffer[obj->field_1c++] = 0;
        }
        fn_80361B7C(obj);
        while (obj->field_1c < 56) {
            obj->buffer[obj->field_1c++] = 0;
        }
    } else {
        obj->buffer[obj->field_1c++] = 0x80;
        while (obj->field_1c < 56) {
            obj->buffer[obj->field_1c++] = 0;
        }
    }
    obj->buffer[56] = obj->field_18 >> 24;
    obj->buffer[57] = obj->field_18 >> 16;
    obj->buffer[58] = obj->field_18 >> 8;
    obj->buffer[59] = obj->field_18;
    obj->buffer[60] = obj->field_14 >> 24;
    obj->buffer[61] = obj->field_14 >> 16;
    obj->buffer[62] = obj->field_14 >> 8;
    obj->buffer[63] = obj->field_14;
    fn_80361B7C(obj);
}
