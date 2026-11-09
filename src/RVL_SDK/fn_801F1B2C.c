#include <revolution/GX/GXHardware.h>
#include <revolution/GX/GXInit.h>
#pragma force_active on

void fn_801F1B2C(int arg0, const unsigned char *arg1, int arg2,
                 const unsigned char *arg3)
{
    unsigned int value4;
    unsigned int value5;
    unsigned int value0;
    unsigned int value1;
    unsigned int value2;
    unsigned int value3;

    if (arg0 != 0) {
        value0 = 0;
        value0 = __rlwimi(value0, arg1[0], 0, 28, 31);
        value0 = __rlwimi(value0, arg1[1], 4, 24, 27);
        value0 = __rlwimi(value0, arg1[2], 8, 20, 23);
        value0 = __rlwimi(value0, arg1[3], 12, 16, 19);
        value0 = __rlwimi(value0, arg1[4], 16, 12, 15);
        value0 = __rlwimi(value0, arg1[5], 20, 8, 11);
        value0 = __rlwimi(value0, 1, 24, 0, 7);

        value1 = 0;
        value1 = __rlwimi(value1, arg1[6], 0, 28, 31);
        value1 = __rlwimi(value1, arg1[7], 4, 24, 27);
        value1 = __rlwimi(value1, arg1[8], 8, 20, 23);
        value1 = __rlwimi(value1, arg1[9], 12, 16, 19);
        value1 = __rlwimi(value1, arg1[10], 16, 12, 15);
        value1 = __rlwimi(value1, arg1[11], 20, 8, 11);
        value1 = __rlwimi(value1, 2, 24, 0, 7);

        value2 = 0;
        value2 = __rlwimi(value2, arg1[12], 0, 28, 31);
        value2 = __rlwimi(value2, arg1[13], 4, 24, 27);
        value2 = __rlwimi(value2, arg1[14], 8, 20, 23);
        value2 = __rlwimi(value2, arg1[15], 12, 16, 19);
        value2 = __rlwimi(value2, arg1[16], 16, 12, 15);
        value2 = __rlwimi(value2, arg1[17], 20, 8, 11);
        value2 = __rlwimi(value2, 3, 24, 0, 7);

        value3 = 0;
        value3 = __rlwimi(value3, arg1[18], 0, 28, 31);
        value3 = __rlwimi(value3, arg1[19], 4, 24, 27);
        value3 = __rlwimi(value3, arg1[20], 8, 20, 23);
        value3 = __rlwimi(value3, arg1[21], 12, 16, 19);
        value3 = __rlwimi(value3, arg1[22], 16, 12, 15);
        value3 = __rlwimi(value3, arg1[23], 20, 8, 11);
        value3 = __rlwimi(value3, 4, 24, 0, 7);
    } else {
        value0 = 0x01666666;
        value1 = 0x02666666;
        value2 = 0x03666666;
        value3 = 0x04666666;
    }

    WGPIPE.uc = 0x61;

    value5 = __rlwimi(0, 83, 24, 0, 7);
    value4 = 0;
    value4 = __rlwimi(value4, 84, 24, 0, 7);

    WGPIPE.ui = value0;
    WGPIPE.uc = 0x61;
    WGPIPE.ui = value1;
    WGPIPE.uc = 0x61;
    WGPIPE.ui = value2;
    WGPIPE.uc = 0x61;
    WGPIPE.ui = value3;

    if (arg2 != 0) {
        value5 = __rlwimi(value5, arg3[0], 0, 26, 31);
        value5 = __rlwimi(value5, arg3[1], 6, 20, 25);
        value5 = __rlwimi(value5, arg3[2], 12, 14, 19);
        value5 = __rlwimi(value5, arg3[3], 18, 8, 13);
        value4 = __rlwimi(value4, arg3[4], 0, 26, 31);
        value4 = __rlwimi(value4, arg3[5], 6, 20, 25);
        value4 = __rlwimi(value4, arg3[6], 12, 14, 19);
    } else {
        value5 &= ~0xFFF;
        value4 = __rlwimi(value4, 21, 0, 26, 31);
        value5 = __rlwimi(value5, 21, 12, 14, 19);
        value5 = __rlwimi(value5, 22, 18, 8, 13);
        value4 &= ~0x3FFC0;
    }

    WGPIPE.uc = 0x61;
    WGPIPE.ui = value5;
    WGPIPE.uc = 0x61;
    WGPIPE.ui = value4;

    __GXData->lastWriteWasXF = 0;
}
