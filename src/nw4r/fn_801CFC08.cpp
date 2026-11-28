#include <types.h>
#pragma force_active on

extern "C" {
int OSDisableInterrupts(void);
void OSRestoreInterrupts(int);
void fn_8015C2BC(void* list, int* out);
}

extern "C" int fn_801CFC08(unsigned char* arg0) {
    int outer;
    int var_r30_3;
    int var_r30_2;
    int var_r30;
    int temp_r30;
    int temp_r30_2;
    int temp_r30_3;
    int temp_r29;
    int temp_r29_2;
    int temp_r29_3;
    int sp10;
    int spC;
    int sp8;

    outer = OSDisableInterrupts();
    temp_r30 = OSDisableInterrupts();
    if (*(int*)(arg0 + 0x18) == 0) {
        OSRestoreInterrupts(temp_r30);
        var_r30_3 = 0;
    } else {
        temp_r29 = *(int*)(arg0 + 0x1C);
        sp10 = temp_r29;
        fn_8015C2BC(arg0 + 0x18, &sp10);
        OSRestoreInterrupts(temp_r30);
        var_r30_3 = temp_r29 - 4;
    }
    if (var_r30_3 != 0) {
        OSRestoreInterrupts(outer);
        return var_r30_3;
    }
    temp_r30_2 = OSDisableInterrupts();
    if (*(int*)(arg0 + 0xC) == 0) {
        OSRestoreInterrupts(temp_r30_2);
        var_r30_2 = 0;
    } else {
        temp_r29_2 = *(int*)(arg0 + 0x10);
        spC = temp_r29_2;
        fn_8015C2BC(arg0 + 0xC, &spC);
        OSRestoreInterrupts(temp_r30_2);
        var_r30_2 = temp_r29_2 - 4;
    }
    if (var_r30_2 != 0) {
        OSRestoreInterrupts(outer);
        return var_r30_2;
    }
    temp_r30_3 = OSDisableInterrupts();
    if (*(int*)(arg0 + 0x0) == 0) {
        OSRestoreInterrupts(temp_r30_3);
        var_r30 = 0;
    } else {
        temp_r29_3 = *(int*)(arg0 + 0x4);
        sp8 = temp_r29_3;
        fn_8015C2BC(arg0, &sp8);
        OSRestoreInterrupts(temp_r30_3);
        var_r30 = temp_r29_3 - 4;
    }
    if (var_r30 != 0) {
        OSRestoreInterrupts(outer);
        return var_r30;
    }
    OSRestoreInterrupts(outer);
    return 0;
}
