#include <gf/gf_scene.h>
#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_24_2EF8(void*);
extern "C" void fn_80073F84(void*, int);
extern void* g_sndSystem;
struct Obj {
    char pad[0x368];
    char a, b;
    char pad2[6];
    int c;
    char pad3[0x1c];
    void* d;
};
extern "C" void fn_1_EA9C(Obj* self) {
    switch (gfSceneManager::getInstance()->m_memoryLayout) {
    case 0:
        self->a = 0;
        self->b = 0;
        break;
    case 1:
        self->a = 1;
        self->b = 1;
        break;
    default:
        self->a = 0;
        self->b = 0;
        break;
    }
    void* p = __nw__FUlQ25Heaps8HeapType(0x204, 0x2a);
    if (p != 0) p = fn_24_2EF8(p);
    self->d = p;
    self->c = 0;
    fn_80073F84(g_sndSystem, 0);
}