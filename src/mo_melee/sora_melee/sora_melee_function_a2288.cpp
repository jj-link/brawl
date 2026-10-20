#pragma force_active on
typedef unsigned int u32;

struct WorkBase {
    u32 unused[2];
};

struct Work : WorkBase {
    virtual void unused00();
    virtual void unused01();
    virtual void unused02();
    virtual void unused03();
    virtual void unused04();
    virtual void unused05();
    virtual void unused06();
    virtual void unused07();
    virtual void unused08();
    virtual void unused09();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual u32 operation(u32);
};

struct WorkModule {
    unsigned char unused[0x1c];
    Work* banks[16];
};

extern "C" u32 fn_27_A2288(WorkModule* self, u32 index) {
    return self->banks[index >> 28]->operation(index & 0x00ffffff);
}
