#pragma force_active on
struct V {
    virtual void pad0(); virtual void pad1(); virtual void pad2(); virtual void pad3();
    virtual void pad4(); virtual void pad5(); virtual void pad6(); virtual void pad7();
    virtual void pad8(); virtual void pad9(); virtual void pad10(); virtual void pad11();
    virtual void pad12(); virtual void pad13();
    virtual void func();
};

extern "C" void fn_113_1BFCC(V* obj) {
    obj->func();
}
