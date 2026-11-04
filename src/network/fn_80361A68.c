#include <types.h>
#pragma force_active on
struct Obj_80361A68 { char _0x00[0x14]; s32 field_14; s32 field_18; s16 field_1c; u8 buffer[0x40]; char _pad[2]; s32 field_60; s32 field_64; };
extern void fn_80361B7C(void*);
s32 fn_80361A68(struct Obj_80361A68* obj, u8* data, s32 count) {
    if (count == 0) return 0;
    if (obj == NULL || data == NULL) return 1;
    if (obj->field_60 != 0) { obj->field_64 = 3; return 3; }
    if (obj->field_64 != 0) return obj->field_64;
    while (count-- != 0 && obj->field_64 == 0) {
        obj->buffer[obj->field_1c++] = *data;
        obj->field_14 += 8;
        if (obj->field_14 == 0) {
            obj->field_18 += 1;
            if (obj->field_18 == 0) obj->field_64 = 1;
        }
        if (obj->field_1c == 0x40) fn_80361B7C(obj);
        data++;
    }
    return 0;
}