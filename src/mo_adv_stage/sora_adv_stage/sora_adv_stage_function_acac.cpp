#pragma force_active on
typedef unsigned long u32;

struct Entry {
    unsigned char kind;
    unsigned char sub;
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

struct Stage {
    char pad[0x1a0];
    void* resource;
};

struct GroundBase {
    char pad[0x3c];
};

struct Ground : GroundBase {
#define V(n) virtual void n();
    V(f0) V(f1) V(f2) V(f3) V(f4) V(f5) V(f6) V(f7) V(f8) V(f9)
    V(f10) V(f11) V(f12) V(f13) V(f14) V(f15) V(f16) V(f17) V(f18) V(f19)
    V(f20) V(f21) V(f22) V(f23) V(f24) V(f25) V(f26) V(f27) V(f28) V(f29)
    V(f30) V(f31) V(f32) V(f33) V(f34) V(f35) V(f36)
    virtual void startup(void*, u32, u32);
    V(g0) V(g1) V(g2) V(g3) V(g4) V(g5) V(g6) V(g7) V(g8) V(g9)
    V(g10) V(g11) V(g12) V(g13) V(g14) V(g15) V(g16) V(g17) V(g18) V(g19)
    V(g20) V(g21) V(g22) V(g23) V(g24) V(g25) V(g26) V(g27) V(g28) V(g29)
    V(g30) V(g31) V(g32) V(g33) V(g34) V(g35) V(g36) V(g37) V(g38) V(g39)
    V(g40) V(g41)
    virtual void setEntry(Entry*);
};

extern "C" {
extern char lbl_40_data_248[];
Ground* fn_40_26FB0(short, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);
Container* searchContainer__20stDataMultiContainerFUlUl(void*, u32, u32);
void* __nw__FUlQ25Heaps8HeapType(u32, int);
void __dl__FPv(void*);
void testCollDataInit__5StageFP9gfArchiveP10grCollDataUl(Stage*, void*, void*, u32);
void* create__11grCollisionFP5StagePvP6Groundi(Stage*, void*, Ground*, int);
void setCollision__5StageFP11grCollision(Stage*, void*);

void fn_40_ACAC(Stage* stage, u32 type, void* multi) {
    void* d;
    unsigned char s;
    Entry* e;
    Ground* g;
    Container* c;
    u32 index = 0;
    u32 i;
    while ((c = searchContainer__20stDataMultiContainerFUlUl(multi, type, index++)) != 0) {
        for (i = 0; i < c->data->count; ++i) {
            e = c->get(i);
            g = fn_40_26FB0((short)e->kind, lbl_40_data_248);
            if (g) {
                addGround__5StageFP6Ground(stage, g);
                g->setEntry(e);
                g->startup(stage->resource, 0, 0);
                s = e->sub;
                if (s != 0xff) {
                    d = __nw__FUlQ25Heaps8HeapType(0x28, 0xf);
                    if (d) {
                        testCollDataInit__5StageFP9gfArchiveP10grCollDataUl(stage, stage->resource, d, s);
                        setCollision__5StageFP11grCollision(stage, create__11grCollisionFP5StagePvP6Groundi(stage, d, g, 1));
                    }
                    __dl__FPv(d);
                }
            }
        }
    }
}
}
