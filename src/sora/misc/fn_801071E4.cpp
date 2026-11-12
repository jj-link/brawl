#pragma force_active on
#include <types.h>
#include <gf/gf_3d_scene.h>
#include <if/if_adv_task.h>

class IfAdvVirtObj {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void setup(s32 idx, void* p);
};

struct IfAdvSub {
    char pad[0x110];
    void* p110;
};

struct IfAdvMngr {
    ifAdvTask* task;          /* 0x00 */
    u8 flag4 : 1;             /* 0x04 */
    u8 rest4 : 7;
    IfAdvVirtObj* obj8;       /* 0x08 */
    u32 unkC;                 /* 0x0C */
    char pad10[0x44 - 0x10];
    void* p44;                /* 0x44 */
    char pad48[0x74 - 0x48];
    IfAdvSub* p74;            /* 0x74 */
    char pad78[0x108 - 0x78];
    void* p108;               /* 0x108 */
    char pad10c[0x110 - 0x10C];
    u8 b110;                  /* 0x110 */
};

extern "C" {
void fn_800DDA50(unsigned char* self, unsigned int a1, int a2, bool a3, void* a4, unsigned int a5);
void fn_800DFC70(void* self);
void fn_8010C004(void* self);
void fn_80108E44(void* self);
void fn_8010852C(void* self);
u32 fn_801B354C(void* self, s32 idx);

void fn_801071E4(IfAdvMngr* self) {
    self->flag4 = 0;
    fn_800DDA50((unsigned char*)self->p108, (u32)self->p44, 0, 0U, (void*)0, 0U);
    fn_800DFC70(self->p44);
    fn_8010C004(self->p44);
    fn_80108E44(self->p44);
    fn_8010852C(self->p44);
    self->obj8->setup(0, self->p44);
    self->obj8->setup(1, self->p74->p110);
    self->unkC = 0;
    fn_801B354C(self->obj8, 0);
    if (self->b110 != 0) {
        g_gfSceneRoot->add(gfSceneRoot::Layer_Info, (nw4r::g3d::ScnMdl*)self->obj8);
    }
    self->task = ifAdvTask::create();
}
}
