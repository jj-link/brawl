#pragma force_active on
struct Data {
    unsigned char padding[0xD0];
    int value;
};

struct Globals {
    unsigned char padding[0x24];
    Data* data;
};

extern Globals lbl_27_bss_3210;

extern "C" int fn_27_149464(void*, int kind) {
    switch (kind) {
    case 3:
        return lbl_27_bss_3210.data->value;
    default:
        return 0;
    }
}
