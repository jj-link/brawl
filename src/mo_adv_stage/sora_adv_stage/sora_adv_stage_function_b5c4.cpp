#pragma force_active on
typedef unsigned long u32;

struct Entry {
    unsigned char pad[0x2c];
    unsigned char type;
};

struct Count {
    u32 pad;
    u32 count;
};

struct Container {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Entry* get(u32);

    u32 pad;
    Count* data;
};

struct GroundBase {
    unsigned char pad[0x3c];
};

struct Ground : GroundBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void startup(void*, int, int);
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void setData(Entry*);
};

struct Stage {
    unsigned char pad[0x1a0];
    void* resource;
};

struct stDataMultiContainer;

extern "C" {
extern char lbl_40_data_130[];

Ground* fn_40_1C014(short, int, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);
Container* searchContainer__20stDataMultiContainerFUlUl(
    stDataMultiContainer*, u32, u32);

void fn_40_B5C4(Stage* stage, u32 kind, stDataMultiContainer* multi)
{
    Ground* ground;
    Container* container;
    u32 index = 0;
    u32 i;
    Entry* entry;

    while ((container = searchContainer__20stDataMultiContainerFUlUl(
                multi, kind, index++)) != 0) {
        for (i = 0; i < container->data->count; ++i) {
            entry = container->get(i);
            ground = fn_40_1C014((short)entry->type, 0, lbl_40_data_130);
            ground->setData(entry);
            addGround__5StageFP6Ground(stage, ground);
            ground->startup(stage->resource, 0, 0);
        }
    }
}
}
