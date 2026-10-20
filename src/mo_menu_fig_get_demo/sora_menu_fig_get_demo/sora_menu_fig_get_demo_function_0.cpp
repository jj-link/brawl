#pragma force_active on
typedef unsigned int u32;

struct DemoSource {
    virtual int count() = 0;
    virtual void reset() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual u32 get() = 0;
    virtual void slot1C() = 0;
    virtual void next() = 0;
};

struct DemoArgs {
    u32 first;
    u32 second;
    DemoSource* source;
};

struct Demo {
    char pad0[0x44];
    u32 first;
    u32 second;
    u32 entries[100];
    int count;
    DemoSource* source;
    char pad1[0xC];
    u32 state;
    char pad2[0x1180];
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" Demo* fn_26_F8(Demo*);

extern "C" Demo* fn_26_0(DemoArgs* __restrict args) {
    int i;
    Demo* obj = (Demo*)__nw__FUlQ25Heaps8HeapType(0x1374, 0x2A);
    if (obj) {
        obj = fn_26_F8(obj);
    }
    obj->first = args->first;
    u32 second = args->second;
    obj->source = args->source;
    obj->second = second;
    if (obj->source) {
        obj->source->reset();
        obj->count = obj->source->count();
        Demo* cursor = obj;
        for (i = 0; i < obj->count; ++i) {
            cursor->entries[0] = obj->source->get();
            obj->source->next();
            cursor = (Demo*)((char*)cursor + 4);
        }
    }
    obj->state = 0;
    return obj;
}
