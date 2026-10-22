#include <types.h>
#pragma force_active on

struct fn_8035B078_Obj {
    s32* arr;
    s32 field_04;
    s32 pad_08;
    s32 (*callback)(s32, s32);
    s32 field_10;
};

extern s32 fn_8035AAD8(s32, s32, s32, s32, s32);
extern void fn_8035A5C8(s32, s32);
extern void fn_8035AA08(s32, s32, s32, s32);

void fn_8035B078(struct fn_8035B078_Obj* obj, s32 arg1) {
    if (obj != NULL) {
        s32 result = obj->callback(arg1, obj->field_04);
        s32 ret = fn_8035AAD8(obj->arr[result], arg1, obj->field_10, 0, 0);
        if (ret == -1) {
            fn_8035A5C8(obj->arr[result], arg1);
        } else {
            fn_8035AA08(obj->arr[result], arg1, ret, *(s32*)obj);
        }
    }
}
