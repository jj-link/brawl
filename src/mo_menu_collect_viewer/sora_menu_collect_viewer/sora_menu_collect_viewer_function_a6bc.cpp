#include <gf/gf_heap_manager.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#pragma force_active on
struct Entry { const char* name; unsigned char first, last, argument, pad; };
struct Anim { char pad[0x18]; void* controller; };
struct Object { char pad[0x10]; void* model; Anim* anim; };
struct Menu {
    char pad0[0x40]; Object* objects[12];
    nw4r::g3d::ScnMdl* scenes[4];
    char pad80[0xa8]; int state; char pad12c[4]; void* manager;
    char pad134[0x10]; int arg7; int offset;
    char pad14c[8]; int error; int error2;
    char pad15c[0x108]; void* context;
};
class Controller {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f10(float);
};
extern "C" {
extern Entry lbl_6_rodata_6F0[], lbl_6_rodata_710[], lbl_6_rodata_750[];
extern unsigned char lbl_6_rodata_708[];
extern char lbl_6_data_7EC[];
extern float lbl_6_rodata_6E8;
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
void fn_6_AB48(Menu*, Entry*, int, void*, int, int);
void fn_6_AC44(Menu*, void*, int, int);
void* fn_801542C4(void*, int);
void fn_800B96E8(void*, int);
void fn_800B5854(void*, int, int, int, int);
void fn_80153488(void*);
void fn_80153498(void*, int);
int fn_80153504(void*, int);
int fn_80153D10(void*);
int fn_80154CD8();
}
extern "C" void fn_6_A6BC(Menu* self, char* context, void* a2, void* a3, void* a4, void* a5, int a6, int a7, int a8, int offset) {
    int temp[2];
    int i;
    int count;
    unsigned char* data;
    void* heap;
    int failed;
    self->scenes[1] = (nw4r::g3d::ScnMdl*)a8;
    self->arg7 = a7;
    self->context = context;
    failed = 0;
    self->offset = offset;
    *(int*)((char*)self + 0x7c) = a6;
    fn_6_AB48(self, lbl_6_rodata_6F0, 3, a2, offset, 0x2b);
    data = (unsigned char*)((unsigned long)lbl_6_rodata_708 | 0);
    heap = gfHeapManager::getMEMAllocator((Heaps::HeapType)0x2b);
    count = data[1] - data[0];
    if (count <= 0) count = 1;
    for (i = 0; i < count; i++) {
        nw4r::g3d::ScnMdl* mdl = nw4r::g3d::ScnMdl::Construct(heap, 0, data[3], self->objects[data[2] + i]->model);
        self->scenes[data[0] + i] = mdl;
    }
    fn_6_AB48(self, lbl_6_rodata_710, 8, a3, offset, 0x2b);
    fn_6_AB48(self, lbl_6_rodata_750, 1, a4, offset, 0x2b);
    fn_6_AC44(self, a5, 0x2a, 0x2b);
    void* p = operator new(0x390, (Heaps::HeapType)0x2a);
    if (p) p = fn_801542C4(p, 0x2b);
    self->manager = p;
    fn_800B96E8((char*)self + 0x80, 0xf0);
    Object* obj1 = self->objects[1];
    Object* obj2 = self->objects[2];
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scenes[0], obj1->model, lbl_6_data_7EC);
    fn_800B5854(obj1, 1, 3, 0, 0);
    ((Controller*)obj1->anim->controller)->f10(lbl_6_rodata_6E8);
    fn_800B5854(obj2, 1, 1, 0, 0);
    ((Controller*)obj2->anim->controller)->f10(lbl_6_rodata_6E8);
    fn_80153488(temp);
    int ok;
    if (!fn_80153504(temp, *(int*)(context + 0xe4))) {
        fn_80153498(temp, -1);
        ok = 0;
    } else if (fn_80153D10(temp)) {
        fn_80153498(temp, -1);
        ok = 0;
    } else {
        fn_80153498(temp, -1);
        ok = 1;
    }
    if (!ok) {
        self->error2 = 0;
        failed = 1;
        self->error = 14;
    } else if (!fn_80154CD8()) {
        self->error2 = 0;
        failed = 1;
        self->error = 13;
    }
    int state = 0;
    if (failed) state = 11;
    self->state = state;
}