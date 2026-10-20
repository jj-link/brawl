#pragma force_active on
typedef unsigned int u32;

class Work {
    u32 reserved[2];

public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void call(u32, u32);
};

struct Module {
    unsigned char reserved[0x1c];
    Work* works[16];
};

extern "C" void fn_27_A2160(Module* self, u32 value, u32 index) {
    self->works[index >> 28]->call(value, index & 0x00ffffff);
}
