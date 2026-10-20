#pragma force_active on
extern "C" {

extern int lbl_1_bss_17A0[35];
extern int lbl_1_data_6DE8[35];
extern int lbl_1_bss_182C;

int randi__Fl(long);
bool fn_8004F4A0(int);

inline int resolve(int value) {
    switch (value) {
    default:
        return value;
    case 72:
        return randi__Fl(3) * 2 + 29;
    case 73:
        return randi__Fl(2) + 3;
    case 74:
        return randi__Fl(2) + 14;
    }
}

int fn_1_229A4() {
    int result = 62;

    while (result == 62) {
        if (lbl_1_bss_182C >= 35) {
            for (int i = 0; i < 4; ++i) {
                lbl_1_bss_17A0[i] = lbl_1_bss_17A0[i + 31];
            }
            lbl_1_bss_182C = 5;
        }

        int index = randi__Fl(35);
        bool retry = true;
        int value = 0;

        while (retry == true) {
            value = lbl_1_data_6DE8[index];
            retry = false;

            for (int i = 0; i < lbl_1_bss_182C; ++i) {
                if (value == lbl_1_bss_17A0[i]) {
                    retry = true;
                    index = (index + 1) % 35;
                }
            }
        }

        lbl_1_bss_17A0[lbl_1_bss_182C] = value;
        ++lbl_1_bss_182C;

        value = resolve(value);
        if (fn_8004F4A0(value) == true) {
            result = value;
        }
    }

    return result;
}

}
