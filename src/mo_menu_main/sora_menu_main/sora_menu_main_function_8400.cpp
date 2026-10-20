#pragma force_active on
extern "C" void fn_801AC758(void*);

class VBase {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
};

extern "C" void fn_2_8400(char* root) {
    int off = 0;
    for (int i = 0; i < 2; i++) {
        char* base = *reinterpret_cast<char**>(root + 0x40);
        void* first = *reinterpret_cast<void**>(base + off);
        if (first != 0) {
            fn_801AC758(first);
        }
        VBase* obj = *reinterpret_cast<VBase**>(base + off + 4);
        if (obj != 0) {
            obj->f9();
        }
        off += 8;
    }
}
