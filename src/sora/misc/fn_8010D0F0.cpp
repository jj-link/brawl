#include <gf/gf_heap_manager.h>
#include <nw4r/g3d/g3d_obj.h>
#pragma force_active on

extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_80100FA8(void*);
void fn_800C1D2C(void*);
nw4r::g3d::G3dObj* fn_801AB6CC(MEMAllocator*, void*, int);
void fn_8010D21C(void*);
}
struct Obj {
    void* first;
    nw4r::g3d::G3dObj* scene;
    int third;
    char arr1[0xa0];
    char arr2[8];
    char arr3[0xa0];
    char arr4[0x280];
    int a;
    int skip;
    int b,c,d,e,f,g,h,i,j;
    float x,y;
    unsigned char flag1:1;
    unsigned char flag2:1;
    unsigned char rest:6;
};
extern "C" Obj* fn_8010D0F0(Obj* self, void* arg, int flag) {
    self->first = arg;
    self->scene = 0;
    self->third = 0;
    __construct_array(self->arr1, fn_80100FA8, fn_800C1D2C, 4, 0x28);
    __construct_array(self->arr2, fn_80100FA8, fn_800C1D2C, 4, 2);
    __construct_array(self->arr3, fn_80100FA8, fn_800C1D2C, 4, 0x28);
    __construct_array(self->arr4, fn_80100FA8, fn_800C1D2C, 4, 0xa0);
    self->a = 0;
    self->b = 0; self->c = 0; self->d = 0; self->e = 0; self->f = 0;
    self->g = 0; self->h = 0; self->i = 0; self->j = 0;
    self->x = 0.0f; self->y = 0.0f;
    self->flag1 = flag;
    self->flag2 = 0;
    nw4r::g3d::G3dObj* scene = fn_801AB6CC(gfHeapManager::getMEMAllocator((Heaps::HeapType)0x28), 0, 0xf3);
    if (self->scene) self->scene->Destroy();
    self->scene = scene;
    fn_8010D21C(self);
    return self;
}