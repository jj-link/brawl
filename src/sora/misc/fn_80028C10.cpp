#pragma force_active on
class gfPadSystem {
public:
    static gfPadSystem* create();
    gfPadSystem();
};

extern "C" {
gfPadSystem* __ct__11gfPadSystemFv(gfPadSystem* self);
void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
}

extern gfPadSystem* g_gfPadSystem;

gfPadSystem* gfPadSystem::create() {
    if (g_gfPadSystem == 0) {
        gfPadSystem* p = (gfPadSystem*)__nw__FUlQ25Heaps8HeapType(0xB78, 1);
        if (p != 0) {
            p = __ct__11gfPadSystemFv(p);
        }
        g_gfPadSystem = p;
    }
    return g_gfPadSystem;
}
