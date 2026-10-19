#pragma force_active on
struct Sub {
    int field_00;
    int field_04;
};

struct SelChar {
    char pad_00[0x48];
    Sub* field_48;
};

extern "C" int fn_10_1C848(SelChar* sel) {
    return sel->field_48->field_04;
}
