#pragma force_active on

typedef unsigned int u32;
typedef unsigned char u8;

struct SOObj;
struct Object;

struct SEntry {
    char pad[0x11];
    unsigned char flags;
    char pad2[0x2C - 0x12];
    Object* source;
};

struct Container {
    virtual void v0();
    virtual SEntry* const* get(int index);
    virtual void v1();
    virtual int count();
};

struct Collection {
    char pad[4];
    Container entries;
};

struct Holder {
    virtual void h0();
    virtual void h1();
    virtual void h2();
    virtual void h3();
    virtual void h4();
    virtual void h5();
    virtual void h6();
    virtual void h7();
    virtual void h8();
    virtual void h9();
    virtual void h10();
    virtual void h11();
    virtual void h12();
    virtual void h13();
    virtual void h14();
    virtual void h15();
    virtual void h16();
    virtual void h17();
    virtual void h18();
    virtual void h19();
    virtual void h20();
    virtual void h21();
    virtual void h22();
    virtual void h23();
    virtual void h24();
    virtual void h25();
    virtual void h26();
    virtual void h27();

    Collection collection;
};

struct SPad {
    unsigned int value;
};

struct Provider : SPad {
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void call(void*, void*, void*, u8);
};

struct Owner {
    char pad[0x154];
    Holder* holder;
};

extern "C" Provider* fn_27_1240B8(Object* self);

extern "C" void fn_27_10D9F0(Owner* self, void* arg1, void* arg2, u32 arg3, void* arg4) {
    u8 flag = 0;
    if (arg3 == 1) flag |= 1;
    int count = self->holder->collection.entries.count();
    for (int i = 0; i < count; ++i) {
        SEntry* entry = *self->holder->collection.entries.get(i);
        if (!((entry->flags >> 1) & 1)) {
            Provider* provider = fn_27_1240B8(entry->source);
            provider->call(arg4, arg1, arg2, flag);
        }
    }
}
