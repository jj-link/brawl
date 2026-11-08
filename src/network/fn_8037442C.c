#include <types.h>
#pragma force_active on

struct Obj {
    int field0;
    u16 field4;
    void *field8;
    char pad[0x7c];
    u32 field88;
};
extern int fn_803783C4(void *, int, u16, u8 *, int);
extern u32 fn_8035D728(void);

int fn_8037442C(struct Obj *obj, u8 *buf, int arg) {
    if (fn_803783C4(obj->field8, obj->field0, obj->field4, buf, arg) == 0) {
        return 0;
    }
    obj->field88 = fn_8035D728();
    return 1;
}
