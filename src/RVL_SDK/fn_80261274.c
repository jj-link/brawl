#include <types.h>
#pragma force_active on

typedef struct {
    u32 unk0;
    s32 unk4;
} Struct_80261274;

extern s32 fn_80261108(s32, Struct_80261274*);

s32 fn_80261274(Struct_80261274* arg0) {
    u32 var_r31;
    s32 var_r30;
    s32 ret;
    
    var_r31 = arg0->unk0;
    var_r30 = arg0->unk4;
    var_r30 -= 8;
    
    while (var_r30 >= 0) {
        ret = fn_80261108(-1, arg0);
        if (ret < 0) {
            return ret;
        }
        if ((u8)var_r31 == 0xFF) {
            ret = fn_80261108(-1, arg0);
            if (ret < 0) {
                return ret;
            }
        }
        var_r31 >>= 8;
        var_r30 -= 8;
    }
    
    arg0->unk4 = 0;
    arg0->unk0 = 0;
    return 0;
}
