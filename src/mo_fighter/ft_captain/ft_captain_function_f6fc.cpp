#pragma force_active on
extern "C" {

extern unsigned char lbl_100_data_6780[0x40];

void fn_100_F6FC(unsigned char **ptr) {
    *ptr = lbl_100_data_6780;
}

}

