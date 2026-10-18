#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Info {
    u8 pad[0x24];
    u8 flags;
};

class SubA {
public:
    virtual void a0();
    virtual Info* getInfo();
};

class SubB {
public:
    virtual void b0();
    virtual void* doIt(u32 p);
};

struct Outer {
    u8 pad[0x90];
    void* m90;
};

extern "C" void fn_27_20084(void* p, float f);

extern "C" void fn_27_17C10(Outer* self, u32 p2, float f) {
    SubA* a = (SubA*)self->m90;
    Info* info = a->getInfo();
    if (((info->flags >> 5) & 1) == 0) {
        SubB* b = (SubB*)self->m90;
        void* r = b->doIt(p2);
        fn_27_20084(r, f);
    }
}
