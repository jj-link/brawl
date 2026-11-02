#pragma force_active on
#include <ft/ft_common_data_accesser.h>

struct Entry {
    unsigned int m_0;
    unsigned int m_4[2];
};

extern Entry lbl_27_bss_3210[];

extern "C" void fn_27_145944(void) {
    g_ftCommonData.dataCommon = 0;
    g_ftCommonData.commonParams = 0;

    unsigned int* w = (unsigned int*)lbl_27_bss_3210;
    int idx = 0;
    for (int i = 0; i < 3; i++) {
        w[0] = 0; w[1] = 0; w[2] = 0; w[3] = 0; w[4] = 0; w[5] = 0; w[6] = 0; w[7] = 0;
        w[8] = 0; w[9] = 0; w[10] = 0; w[11] = 0; w[12] = 0; w[13] = 0; w[14] = 0; w[15] = 0;
        w[16] = 0; w[17] = 0; w[18] = 0; w[19] = 0; w[20] = 0; w[21] = 0; w[22] = 0; w[23] = 0;
        w[24] = 0; w[25] = 0; w[26] = 0; w[27] = 0; w[28] = 0; w[29] = 0; w[30] = 0; w[31] = 0;
        w[32] = 0; w[33] = 0; w[34] = 0; w[35] = 0; w[36] = 0; w[37] = 0; w[38] = 0; w[39] = 0;
        w[40] = 0; w[41] = 0; w[42] = 0; w[43] = 0; w[44] = 0; w[45] = 0; w[46] = 0; w[47] = 0;
        w += 48;
        idx += 16;
    }

    unsigned int* t = (unsigned int*)&lbl_27_bss_3210[idx];
    t[0] = 0; t[1] = 0; t[2] = 0; t[3] = 0; t[4] = 0; t[5] = 0; t[6] = 0; t[7] = 0;
    t[8] = 0; t[9] = 0; t[10] = 0; t[11] = 0; t[12] = 0; t[13] = 0; t[14] = 0; t[15] = 0;
    t[16] = 0; t[17] = 0; t[18] = 0; t[19] = 0; t[20] = 0;
}
