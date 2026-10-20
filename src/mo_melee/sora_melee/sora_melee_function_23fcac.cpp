#pragma force_active on
extern "C" unsigned int fn_27_23AC10(void*);

class Object {
    unsigned char padding[0x3C];

public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
};

extern "C" void fn_27_23FCAC(Object* self) {
    if (fn_27_23AC10(self) == 1) {
        return;
    }
    unsigned int* flag = (unsigned int*)((char*)self + 0xC4);
    if (*flag == 0) {
        self->v23();
        ((unsigned char*)*flag)[0x198] = 1;
    }
}
