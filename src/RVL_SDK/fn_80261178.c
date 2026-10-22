#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u32 unk0;
    s32 unk4;
    u32 unk8;
    u8 *unkC;
    u8 *unk10;
    u8 *unk14;
} Obj;

s32 fn_80261178(Obj *arg0) {
    s32 var_r0;
    s32 var_r4;
    u8 temp_r5;
    u8 *var_r6;
    u8 *temp_r4;
    u8 *temp_r6;
    u8 temp_r7;

    var_r6 = arg0->unkC;
    if (var_r6 < arg0->unk14) {
        var_r0 = arg0->unk0;
        var_r4 = arg0->unk4;
        do {
            temp_r5 = *var_r6;
            var_r6 += 1;
            var_r4 += 8;
            var_r0 = (var_r0 << 8) + temp_r5;
            if (temp_r5 == 0xFF) {
                var_r6 += 1;
            }
        } while (var_r4 <= 0x18);
        arg0->unk0 = var_r0;
        arg0->unk4 = var_r4;
        arg0->unkC = var_r6;
    } else {
loop_6:
        temp_r4 = arg0->unkC;
        if (arg0->unk10 > temp_r4) {
            temp_r6 = temp_r4 + 1;
            temp_r7 = *temp_r4;
            arg0->unkC = temp_r6;
            arg0->unk0 = (arg0->unk0 << 8) + temp_r7;
            arg0->unk4 = arg0->unk4 + 8;
            if (temp_r7 == 0xFF) {
                arg0->unkC = temp_r6 + 1;
            }
            if (arg0->unk4 <= 0x18) {
                goto loop_6;
            }
        }
    }
    return 0;
}
