#pragma force_active on
struct Foo {
    int m_00;
    int m_04;
    int m_08;
};

extern "C" int fn_27_C98C0(Foo* p) {
    return p->m_08 >> 29;
}
