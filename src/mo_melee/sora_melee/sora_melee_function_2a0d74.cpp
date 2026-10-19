#pragma force_active on
typedef unsigned char u8;

extern "C" {
extern const u8 lbl_27_data_71F6C[];

int fn_27_2A0D74(int, int id) {
    if (id == -3) {
        return 1;
    }
    if (id < 0 || id >= 0xB2) {
        return 0;
    }
    return lbl_27_data_71F6C[id];
}
}
