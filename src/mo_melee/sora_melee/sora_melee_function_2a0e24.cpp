#include <types.h>
#pragma force_active on

extern "C" {
extern const u8 lbl_27_data_71EB8[];
extern s32 lbl_27_data_71BF0[];
s32 fn_27_2A0E24(void* arg0, s32 arg1);
}

s32 fn_27_2A0E24(void* arg0, s32 arg1) {
    s32 r;

    if (((u8*)arg0)[0x14A0] != 0) {
        if (arg1 == -3)
            return -1;

        if (arg1 < 0 || arg1 >= 0xB2)
            r = 0;
        else
            r = lbl_27_data_71EB8[arg1];

        if (r == 0)
            return -1;

        if (arg1 == -3)
            r = 1;
        else if (arg1 < 0 || arg1 >= 0xB2)
            r = -1;
        else
            r = lbl_27_data_71BF0[arg1];

        switch (r) {
        case 1:
        case 6:
        case 7:
            return arg1;
        }
    }

    return -1;
}
