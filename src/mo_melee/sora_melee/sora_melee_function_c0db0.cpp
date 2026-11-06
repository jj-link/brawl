#include <nw4r/g3d/g3d_scnmdl.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual u8 slot20();
    char pad4[0x144];
    u8 layer;
    u8 index;
    char pad14a[6];
    u8 dirty;
    u8 state;
};
struct Class_90D8_base { char pad[8]; };
class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();
    virtual void fn_27_7B22C();
    virtual void fn_27_7AC38();
    virtual void fn_27_7ADE8();
    virtual void fn_27_7AF98();
    virtual void fn_27_7B0B0();
    virtual nw4r::g3d::ScnMdl* fn_27_7ABD8();
};
struct Modules {
    char pad[4];
    Class_90D8* model;
};
struct ModuleAccess {
    char pad[0xd8];
    Modules* modules;
};
struct LayerPair { u8 layer; u8 index; };
extern "C" {
    extern void* g_gfSceneRoot;
    LayerPair fn_80010190(void*, nw4r::g3d::ScnMdl*);
    void* fn_801B006C(nw4r::g3d::ScnMdl::CopiedMatAccess*, int);
    void fn_80191140(void*, u8);
    u32 fn_8018F394(void*);
}
struct MaterialAccess {
    nw4r::g3d::ScnMdl::CopiedMatAccess access;
    int padding;
    MaterialAccess(nw4r::g3d::ScnMdl* model, u32 id) : access(model, id) {}
};
extern "C" void fn_27_C0DB0(Object_vptr_0* self, void*, ModuleAccess* access) {
    if (self->state == 1) {
        u32 i;
        nw4r::g3d::ScnMdl* model = access->modules->model->fn_27_7ABD8();
        if (self->layer == 0xff) {
            void* root = g_gfSceneRoot;
            LayerPair pair = fn_80010190(root, access->modules->model->fn_27_7ABD8());
            self->layer = pair.layer;
            self->index = pair.index;
        }
        u8 value = self->slot20();
        void* data;
        nw4r::g3d::ResMdl resource = model->m_resMdl;
        for (i = 0; i < fn_8018F394(&resource); ++i) {
            MaterialAccess material(model, i);
            data = fn_801B006C(&material.access, 0);
            fn_80191140(&data, value);
        }
        self->dirty = 0;
    }
}
