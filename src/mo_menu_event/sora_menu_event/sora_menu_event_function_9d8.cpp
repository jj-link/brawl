#include <mu/mu_object.h>
#include <gf/gf_heap_manager.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#pragma force_active on

extern "C" {
extern char lbl_9_data_0[];
extern float lbl_9_rodata_98;
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
}

struct Other {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10();
    virtual void apply(void*, void*);
    char pad[0xe0];
    void* value;
};

struct Event {
    char pad0[0x40];
    MuObject* obj40;
    MuObject* obj44;
    char pad48[0x140];
    MuObject* obj188;
    MuObject* obj18c;
    MuObject* obj190;
    MuObject* obj194;
    nw4r::g3d::ScnMdl* model;
    char pad19c[0xc];
    Other* other;
    char pad1ac[0x1610];
    int flag;
};

extern "C" void fn_9_9D8(Event* self) {
    char* data = lbl_9_data_0;
    MuObject* obj;
    MuObject* obj2;
    nw4r::g3d::ScnMdl* model = nw4r::g3d::ScnMdl::Construct(
        gfHeapManager::getMEMAllocator((Heaps::HeapType)0x2b), 0, 0x51, self->obj44->m_sceneModel);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(model, self->obj188->m_sceneModel, data + 0xf8);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(model, self->obj18c->m_sceneModel, data + 0x100);
    if (self->flag == 1) {
        obj = self->obj18c;
        obj->changeNodeAnimNIf(data + 0x108);
        obj->changeClrAnimNIf(data + 0x108);
        obj->setFrameNode(lbl_9_rodata_98);
        obj2 = self->obj40;
        obj2->changeNodeAnimNIf(data + 0x120);
        obj2->changeClrAnimNIf(data + 0x120);
        self->other->apply(self->other->value, self->obj194->m_sceneModel);
    }
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(model, self->obj190->m_sceneModel, data + 0x134);
    self->model = model;
}