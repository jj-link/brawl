#pragma force_active on
typedef unsigned char u8;

extern "C" u8 lbl_27_data_4EDEC[];

extern "C" int fn_27_24810C(int id) {
    int valid = 0;
    if (id >= 0) {
        if (id < 0x33) {
            valid = 1;
        }
    }
    if (valid) {
        return *(u8*)((char*)lbl_27_data_4EDEC + id * 4 + 3);
    } else {
        return 0;
    }
}
