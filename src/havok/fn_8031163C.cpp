#pragma force_active on
class Foo {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    void* m_04;
    void* m_08;
    void* m_0C;
    void* m_10;
    void* m_14;
    void* m_18;
};

class Bar {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(void* p, int a, int b);
};

extern Foo* lbl_805A0EC8;
extern Bar* lbl_805A0EB8;

extern "C" void* __dt__14Class_8031163CFv(void* arg0, int arg1) {
    if (arg0) {
        void* v = *(void**)arg0;
        Foo* p = lbl_805A0EC8;
        p->m_10 = v;
        if (v == p->m_18) {
            p->v4();
        }
        if (arg1 > 0) {
            lbl_805A0EB8->v5(arg0, 8, 0x15);
        }
    }
    return arg0;
}
