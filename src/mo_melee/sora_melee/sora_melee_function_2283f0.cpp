#pragma force_active on
struct Object {
    char pad[0x48];
    unsigned int field48;
};

struct SceneRoot {
    char pad[0x474];
    unsigned int field474;
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" Object* fn_27_228454(Object*, void*, void*);
extern "C" SceneRoot* g_gfSceneRoot;

extern "C" Object* fn_27_2283F0(void* a, void* b) {
    Object* p = (Object*)__nw__FUlQ25Heaps8HeapType(0x28C, 15);
    if (p)
        p = fn_27_228454(p, a, b);
    g_gfSceneRoot->field474 = p->field48;
    return p;
}
