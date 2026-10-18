#pragma force_active on
typedef unsigned long u32;

struct Entry {
    char pad[0x30];
    u32 value;
    unsigned char pad34[2];
    unsigned char kind;
};

struct ContainerBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Entry* get(u32);
};

struct Count {
    u32 unused;
    u32 count;
};

struct Container : ContainerBase {
    u32 unused;
    Count* counts;
};

struct GroundPadding {
    char pad[0x3c];
};

#define V(n) virtual void v##n();
#define W(n) virtual void w##n();

struct Ground : GroundPadding {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7)
    V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15)
    V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23)
    V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31)
    V(32) V(33) V(34) V(35) V(36)
    virtual void setup(void*, int, int);
    W(0) W(1) W(2) W(3) W(4) W(5) W(6) W(7)
    W(8) W(9) W(10) W(11) W(12) W(13) W(14) W(15)
    W(16) W(17) W(18) W(19) W(20) W(21) W(22) W(23)
    W(24) W(25) W(26) W(27) W(28) W(29) W(30) W(31)
    W(32) W(33) W(34) W(35) W(36) W(37) W(38) W(39)
    W(40) W(41)
    virtual void setEntry(Entry*);
};

#undef V
#undef W

class Stage {
public:
    char pad[0x1a0];
    void* resource;
    void addGround(Ground*);
};

class stDataMultiContainer {
public:
    Container* searchContainer(u32, u32);
};

extern "C" {
extern char lbl_40_data_F0[];
Ground* fn_40_3A34C(short, u32, const char*);

void fn_40_CE74(Stage* stage, u32 type, stDataMultiContainer* data) {
    Ground* ground;
    Container* container;
    u32 index = 0;
    u32 i;
    Entry* entry;

    while ((container = data->searchContainer(type, index++)) != 0) {
        for (i = 0; i < container->counts->count; i++) {
            entry = container->get(i);
            ground = fn_40_3A34C(
                (short)entry->kind, entry->value, lbl_40_data_F0);
            if (ground) {
                stage->addGround(ground);
                ground->setEntry(entry);
                ground->setup(stage->resource, 0, 0);
            }
        }
    }
}
}
