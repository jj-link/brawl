#include <types.h>
#include <mt/mt_prng.h>
#pragma force_active on

extern "C" {
extern mtRand lbl_805A0420;
extern int lbl_1_bss_1B88;
extern int lbl_1_bss_1B8C;
extern int lbl_1_data_9990[4];
extern int lbl_1_data_9960[8];
u32 fn_80051A6C(void*);
const double lbl_1_rodata_2490 = 4503599629467648.0;
const float lbl_1_rodata_2498 = 100.0f;
}

extern "C" void fn_1_3C8E8() {
    if (lbl_1_bss_1B88) {
        lbl_1_bss_1B8C = 0;
        return;
    }
    int weights[4] = {lbl_1_data_9990[0], lbl_1_data_9990[1], lbl_1_data_9990[2], lbl_1_data_9990[3]};
    int total = 0;
    for (int i = 0; i < 4; i++) {
        total += weights[i];
    }
    int value = (int)((float)total * lbl_805A0420.randf());
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        if (weights[i] != 0) {
            sum += weights[i];
            if (value < sum) {
                lbl_1_bss_1B8C = i;
                return;
            }
        }
    }
}

extern "C" void fn_1_3CA24() {
    s32 temp_r0;
    s32 var_r31;
    s32 temp_r30;
    s32 temp_r29;
    s32 temp_r28;
    s32 temp_r27;
    s32 temp_r26;
    s32 temp_r25;
    s32 temp_r24;
    s32 var_r23;
    s32 var_r3;
    s32 var_r4;
    if ((s32)(lbl_1_rodata_2498 * lbl_805A0420.randf()) > 0x14) {
        lbl_1_bss_1B88 = 0;
        return;
    }
    temp_r24 = lbl_1_data_9960[0];
    var_r31 = lbl_1_data_9960[7];
    temp_r25 = lbl_1_data_9960[1];
    temp_r26 = lbl_1_data_9960[2];
    temp_r27 = lbl_1_data_9960[3];
    temp_r28 = lbl_1_data_9960[4];
    temp_r29 = lbl_1_data_9960[5];
    temp_r30 = lbl_1_data_9960[6];
    if (fn_80051A6C(lbl_1_data_9960) == 1U) var_r31 = 0;
    var_r23 = temp_r24;
    var_r23 += temp_r25;
    var_r23 += temp_r26;
    var_r23 += temp_r27;
    var_r23 += temp_r28;
    var_r23 += temp_r29;
    var_r23 += temp_r30;
    var_r23 += var_r31;
    temp_r0 = (s32)(lbl_805A0420.randf() * (f32)var_r23);
    s32 weights[8] = {temp_r24, temp_r25, temp_r26, temp_r27, temp_r28, temp_r29, temp_r30, var_r31};
    var_r3 = 0;
#pragma unroll
    for (var_r4 = 0; var_r4 < 8; ++var_r4) {
        if (weights[var_r4] != 0) {
            var_r3 += weights[var_r4];
            if (temp_r0 < var_r3) {
                lbl_1_bss_1B88 = var_r4;
                return;
            }
        }
    }
}