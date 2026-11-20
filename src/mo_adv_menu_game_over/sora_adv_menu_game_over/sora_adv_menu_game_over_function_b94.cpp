#include <gf/gf_3d_scene.h>
#include <gf/gf_heap_manager.h>
#include <gm/gm_global.h>
#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <string.h>
#include <stdio.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_33_data_60[];
extern char lbl_33_data_3E0[];
extern char lbl_33_data_3E4[];
extern int lbl_33_data_C0[3];
extern const f32 lbl_33_rodata_0;
void* fn_80015DB4(void* a, int b, int c, int d, u16 e);
}

struct Name {
    char s[65];
};
struct Values { int v[3]; }; 

struct Self {
    char pad0[0x22c];
    int f22c;
    char pad230[0x234 - 0x230];
    int f234;
    char pad238[0x248 - 0x238];
    nw4r::g3d::ResFile res248;
    nw4r::g3d::ResFile res24c;
    nw4r::g3d::ResFile res250;
    nw4r::g3d::ResFile res254;
    nw4r::g3d::ResFile res258;
    MuObject* obj25c;
    char pad260[0x3f0 - 0x260];
    void* res3f0;
};

extern "C" void fn_33_B94(Self* self) {
    Name n4, n3, n2, n;
    gfHeapManager::getMEMAllocator((Heaps::HeapType)0x2a);
    self->res248 = fn_80015DB4(self->res3f0, 0, 1, 0, (u16)0xFFFE);
    nw4r::g3d::ResFile::Init(&self->res248);
    self->res24c = fn_80015DB4(self->res3f0, 0, 1, 1, (u16)0xFFFE);
    nw4r::g3d::ResFile::Init(&self->res24c);
    self->res250 = fn_80015DB4(self->res3f0, 0, 1, 2, (u16)0xFFFE);
    self->res254 = fn_80015DB4(self->res3f0, 0, 1, 3, (u16)0xFFFE);
    nw4r::g3d::ResFile::Init(&self->res254);
    self->res258 = fn_80015DB4(self->res3f0, 0, 1, 4, (u16)0xFFFE);
    nw4r::g3d::ResFile::Init(&self->res258);

    MuObject* created = MuObject::create(&self->res248, lbl_33_data_60, 10, 0, (Heaps::HeapType)0x2a);
    MuObject* old = self->obj25c;
    if (old != created) {
        delete old;
        self->obj25c = created;
    }

    g_gfSceneRoot->add((gfSceneRoot::LayerType)8, *(nw4r::g3d::ScnMdl**)((char*)self->obj25c + 0x10));

    MuObject* obj = self->obj25c;
    Values tbl = *(Values*)lbl_33_data_C0;
    int val = tbl.v[self->f234];
    int off;
    char* mdl = *(char**)((char*)obj + 8);
    off = *(int*)((char*)mdl + 0x3c);
    const char* src = off ? mdl + off : 0;

    n.s[0] = 0;
    strcat(n.s, src);
    n2 = n;
    strcat(n2.s, lbl_33_data_3E4);
    n3 = n2;
    sprintf(n3.s + strlen(n3.s), lbl_33_data_3E0, val);
    n4 = n3;
    obj->changeClrAnimNIf(n4.s);

    self->f22c = 0;
    float value = lbl_33_rodata_0;
    *(float*)((char*)g_GameGlobal->m_stageData + 4) = value;
    *(float*)((char*)g_GameGlobal->m_stageData + 8) = value;
}
