#pragma force_active on
extern "C" {
extern const float lbl_10_rodata_46C;
extern const float lbl_10_rodata_470;

struct SelCharArg {
    int m_pad;
    float m_value;
};

int fn_10_DC38(SelCharArg* arg) {
    if (arg->m_value >= lbl_10_rodata_46C) {
        return 0;
    }
    if (arg->m_value < lbl_10_rodata_470) {
        return 2;
    }
    return 1;
}
}
