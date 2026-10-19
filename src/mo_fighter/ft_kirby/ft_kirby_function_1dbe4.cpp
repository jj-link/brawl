#pragma force_active on
struct KirbyObj {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void call(int, int, int);
};

extern "C" void* fn_96_1D7E4(void*);

extern "C" void fn_96_1DBE4(void* owner, int a, int b, int c) {
    KirbyObj* obj = (KirbyObj*)fn_96_1D7E4(owner);
    if (obj) {
        obj->call(a, b, c);
    }
}
