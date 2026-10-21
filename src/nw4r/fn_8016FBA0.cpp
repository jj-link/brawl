#pragma force_active on
struct FnSrc {
    char pad[8];
    int val;
};

struct FnDst {
    int m_00;
    FnSrc* m_04;
};

extern "C" void fn_8016FBA0(FnDst* dst, FnSrc* src) {
    if (src == 0) {
        dst->m_00 = 0;
        dst->m_04 = 0;
        return;
    }
    dst->m_00 = src->val;
    dst->m_04 = src;
}
