#pragma force_active on
typedef unsigned long u32;

struct Entry {
    char pad[0x44];
    unsigned char kind;
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
    char pad[0x3c];
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
    virtual void startup(void*, u32, u32);
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual void g13();
    virtual void g14();
    virtual void g15();
    virtual void g16();
    virtual void g17();
    virtual void g18();
    virtual void g19();
    virtual void g20();
    virtual void g21();
    virtual void g22();
    virtual void g23();
    virtual void g24();
    virtual void g25();
    virtual void g26();
    virtual void g27();
    virtual void g28();
    virtual void g29();
    virtual void g30();
    virtual void g31();
    virtual void g32();
    virtual void g33();
    virtual void g34();
    virtual void g35();
    virtual void g36();
    virtual void g37();
    virtual void g38();
    virtual void g39();
    virtual void g40();
    virtual void g41();
    virtual void setEntry(Entry*);
};

struct Stage {
    char pad[0x1a0];
    void* resource;
};

extern "C" {
extern char lbl_40_data_204[];

Ground* fn_40_2992C(short, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);
Container* searchContainer__20stDataMultiContainerFUlUl(void*, u32, u32);

void fn_40_C088(Stage* stage, u32 type, void* multi) {
    Ground* ground;
    Container* container;
    u32 index = 0;

    while ((container = searchContainer__20stDataMultiContainerFUlUl(
                multi, type, index++)) != 0) {
        for (u32 i = 0; i < container->data->count; ++i) {
            Entry* entry = container->get(i);
            ground = fn_40_2992C((short)entry->kind, lbl_40_data_204);
            if (ground) {
                addGround__5StageFP6Ground(stage, ground);
                ground->setEntry(entry);
                ground->startup(stage->resource, 0, 0);
            }
        }
    }
}
}
