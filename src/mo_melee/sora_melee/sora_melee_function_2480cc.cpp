#pragma force_active on
typedef unsigned char u8;

extern "C" const u8 lbl_27_data_4EDEC[];

extern "C" int fn_27_2480CC(int id) {
    int valid = 0;
    if (id >= 0 && id < 0x33)
        valid = 1;

    if (valid != 0) {
        const u8* entry = lbl_27_data_4EDEC + id * 4;
        return entry[1];
    }

    return 0x23;
}
