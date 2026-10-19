#pragma force_active on
extern "C" void* fn_96_1D7E4(void*);

struct Object96 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void method(void*);
};

extern "C" void fn_96_1DCD4(void* arg) {
    Object96* object = (Object96*)fn_96_1D7E4(arg);
    if (object) {
        object->method(*(void**)((char*)arg + 8));
    }
}
