#pragma force_active on
struct LuigiSlotObject {
    unsigned int m_head0;
    unsigned int m_head1;
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20(void* a, void* b);
    virtual void s21();
    virtual unsigned int s22();
};

extern "C" unsigned int fn_99_89F4(LuigiSlotObject* obj, void* a, void* b) {
    unsigned int result = obj->s22();
    if (result == 1) {
        obj->s20(a, b);
    }
    return result;
}
