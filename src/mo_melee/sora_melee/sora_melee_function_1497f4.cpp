#pragma force_active on
struct Data {
    char pad[0x80];
    int value;
};

struct Globals {
    char pad[0x240];
    Data* data;
    char tail[0x54];
};

extern Globals lbl_27_bss_3210;

extern "C" int fn_27_1497F4(void*, int kind) {
    switch (kind) {
    case 0x30:
        return lbl_27_bss_3210.data->value;
    default:
        return 0;
    }
}
