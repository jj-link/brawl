#pragma force_active on
struct S {
    int m_0;
    int m_4;
    int m_8;
};

extern "C" int fn_27_19F52C(S *ptr) {
    return ptr->m_8 >> 28;
}
