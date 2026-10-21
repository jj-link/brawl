#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Work;
typedef void (*WorkFunction)(Work*);
extern "C" WorkFunction __vt__19soGeneralWorkSimple[];

struct Work {
    WorkFunction* baseVtable;
    u8 flag;
    u8 padding[3];
    WorkFunction* vtable;
    void* owner;
    int count0;
    void* data0;
    int count1;
    void* data1;
    int count2;
};

struct DispatchBase {
    u32 unused0;
    u32 unused4;
};

struct Dispatch : DispatchBase {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void reset();
};

struct Object {
    u8 padding[0x68];
    Work work;
};

extern "C" Object* fn_27_31570C(Object* self) {
    Work* work = &self->work;
    work->flag = false;
    work->owner = self;
    work->vtable = __vt__19soGeneralWorkSimple;
    work->baseVtable = __vt__19soGeneralWorkSimple + 2;
    work->count0 = 11;
    work->data0 = (u8*)self + 0x2c;
    work->count1 = 14;
    work->data1 = (u8*)self + 0x64;
    work->count2 = 1;
    ((Dispatch*)work)->reset();
    return self;
}
