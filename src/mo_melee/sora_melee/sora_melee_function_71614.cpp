#pragma force_active on

class acCmdInterpreter;

struct Field {
    acCmdInterpreter* interpreter;
};

class Inner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual Field* getField(int idx);
    virtual void vf23();
    virtual int getIndex();
};

struct Outer {
    unsigned char pad[0x20];
    Inner* inner;
};

extern "C" void fn_27_7021C(acCmdInterpreter* self, void* arg, float f);

extern "C" void fn_27_71614(Outer* self, int unused, void* arg, float f) {
    Field* field;
    int idx = self->inner->getIndex();
    if (idx < 0) {
        field = 0;
    } else {
        field = self->inner->getField(idx);
    }
    if (field != 0) {
        fn_27_7021C(field->interpreter, arg, f);
    }
}
