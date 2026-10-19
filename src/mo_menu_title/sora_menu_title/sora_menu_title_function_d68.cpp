#pragma force_active on
struct SoraMenuTitle {
    char pad_00[0x2c];
    unsigned char flags_hi : 6;
    unsigned char flag_b : 1;
    unsigned char flag_c : 1;
    char pad_2d[0x54 - 0x2d];
    unsigned char field_54;
    char pad_55[0x5c - 0x55];
    int field_5c;
};

extern "C" void fn_24_D68(SoraMenuTitle* p, int val) {
    p->field_54 = val;
    p->flag_b = 0;
    p->field_5c = 0;
}
