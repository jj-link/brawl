#include <types.h>
#pragma force_active on

extern "C" {
int fn_8004F740(int);
int randi__Fl(long);
extern int lbl_1_bss_1830[31];
extern int lbl_1_bss_18AC;
extern int lbl_1_data_6E74[31];

int fn_1_22B28() {
    int result = 0xFF;

    while (result == 0xFF) {
        if (lbl_1_bss_18AC >= 0x1F) {
            lbl_1_bss_1830[0] = lbl_1_bss_1830[30];
            lbl_1_bss_18AC = 1;
        }

        int index = randi__Fl(0x1F);
        int count = lbl_1_bss_18AC;
        bool retry = true;
        int value = 0;

        while (retry == true) {
            value = lbl_1_data_6E74[index];
            retry = false;

            for (int i = 0; i < count; ++i) {
                if (value == lbl_1_bss_1830[i]) {
                    index = (index + 1) % 31;
                    retry = true;
                }
            }
        }

        lbl_1_bss_1830[count] = value;
        lbl_1_bss_18AC += 1;

        if ((unsigned int)fn_8004F740(value) == 1) {
            result = value;
        }
    }

    return result;
}
}
