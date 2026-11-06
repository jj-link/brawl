#include <gm/gm_global.h>
#pragma force_active on

class gfArchive;
class gfModelAnimation;
namespace nw4 { namespace r3g { namespace d { class ScnMdl; } } }

struct Vec3f {
    float x, y, z;
    Vec3f() {}
    Vec3f(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct AdvStageDataView {
    unsigned char pad0[0x5FD];
    unsigned char current;
    unsigned char pad1[0x4916 - 0x5FE];
    unsigned char previous;
};

struct GimmickData {
    float x;
    float y;
    float z;
    char pad0[0x14 - 0x0C];
    unsigned short s14;
    char pad1[0x2C - 0x16];
};

struct GimmickObj {
    char pad0[0x44];
    nw4::r3g::d::ScnMdl** scnMdl;
    gfModelAnimation** modelAnim;
    char pad4C[0x70];
    void* bc;
    char padC0[0x98];
    GimmickData* data;
};

extern "C" void startup__9grGimmickFP9gfArchiveUlUl(void*, gfArchive*, unsigned long, unsigned long);
extern "C" void unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(gfModelAnimation*, nw4::r3g::d::ScnMdl*);
extern "C" void makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(void*, unsigned long, int);
extern "C" void setCalcuCallbackRoot__9grGimmickFUl(void*, unsigned long);
extern "C" void setPos__9grGimmickFP5Vec3f(void*, Vec3f*);
extern "C" void setRot__9grGimmickFP5Vec3f(void*, Vec3f*);
extern "C" void updateCallback__9grGimmickFUl(void*, unsigned long);
extern "C" void createIsValidTrigger__9grGimmickFP13stTriggerData(void*, void*);
extern "C" unsigned short lbl_40_data_11F48[];
extern "C" const float lbl_40_rodata_730;

extern "C" void fn_40_3786C(GimmickObj* self, gfArchive* arg1, unsigned long arg2, unsigned long arg3) {
    startup__9grGimmickFP9gfArchiveUlUl(self, arg1, arg2, arg3);
    self->data = (GimmickData*)self->bc;

    AdvStageDataView* adv = (AdvStageDataView*)g_GameGlobal->m_advData;
    unsigned char current = adv->current;
    unsigned char previous = adv->previous;
    int value = current - previous;
    int lower = current - 5;
    if (value < lower) {
        value = lower;
    }
    if (value < 0) {
        value = 0;
    }
    if (value > 14) {
        value = 14;
    }
    self->data->s14 = lbl_40_data_11F48[(unsigned char)value];

    if (self->modelAnim != 0) {
        unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(*self->modelAnim, *self->scnMdl);
    }

    makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(self, 1, 15);
    setCalcuCallbackRoot__9grGimmickFUl(self, 3);

    GimmickData* d = self->data;
    Vec3f pos;
    pos = Vec3f(d->x, d->y, lbl_40_rodata_730);
    Vec3f rot;
    rot = Vec3f(lbl_40_rodata_730, lbl_40_rodata_730, self->data->z);
    setPos__9grGimmickFP5Vec3f(self, &pos);
    setRot__9grGimmickFP5Vec3f(self, &rot);
    updateCallback__9grGimmickFUl(self, 0);
    createIsValidTrigger__9grGimmickFP13stTriggerData(self, (char*)self->data + 0x2C);
}
