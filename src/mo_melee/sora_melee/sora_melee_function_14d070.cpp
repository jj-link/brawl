#pragma force_active on
extern "C" int fn_27_112268(void*);

struct Object {
    virtual int method0();
    virtual int method1();
    virtual int method2();
    virtual int method3();
    virtual int method4();
    virtual int method5();
    virtual int method6();
    virtual int method7();

    unsigned char padding[0x114];
    int values[24];
    void* helper;
};

struct Argument {
    unsigned char padding[0x30];
    unsigned int index;
};

extern "C" int fn_27_14D070(Object* self, Argument* argument) {
    int base = self->method7();
    int offset = fn_27_112268(self->helper);
    return self->values[argument->index & 31] + (offset + base);
}
