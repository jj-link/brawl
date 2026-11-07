#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0(int);
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    unsigned short type;
    short refs;
};
struct SoHeapAllocator {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void free(void*, unsigned short, int);
};
extern SoHeapAllocator* lbl_805A0EB8;
extern char lbl_80488D58[];
struct Foo {
    char* m_00;
    unsigned short m_04;
    short m_06;
    char* m_08;
    char* m_0c;
    char* m_10;
    char* m_14;
    char* m_18;
    Object_vptr_0* m_1c;
};
extern "C" Foo* fn_8032BF08(Foo* p, int flag) {
    if (p) {
        Object_vptr_0* obj = p->m_1c;
        p->m_00 = lbl_80488D58;
        p->m_08 = lbl_80488D58 + 0x10;
        p->m_0c = lbl_80488D58 + 0x20;
        p->m_10 = lbl_80488D58 + 0x30;
        p->m_14 = lbl_80488D58 + 0x40;
        p->m_18 = lbl_80488D58 + 0x60;
        if (obj && obj->type) {
            if (--obj->refs == 0) {
                if (obj) obj->slot0(1);
            }
        }
        if (flag > 0) lbl_805A0EB8->free(p, p->m_04, 0x25);
    }
    return p;
}