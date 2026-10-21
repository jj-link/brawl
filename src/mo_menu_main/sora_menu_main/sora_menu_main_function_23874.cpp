#include <types.h>
#pragma force_active on

extern "C" void startKeepScreen__17gfKeepFrameBufferFv(void*);
extern "C" void fn_2_24220(void*);
extern "C" void fn_801E9F0C(s32);
extern "C" s32 g_gfApplication;

class Scene {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void remove(s32);
    char pad[0xE0];
    s32 count;
};

struct Self {
    char pad0[0x654];
    Scene* scene;
    char pad1[0x66C - 0x658];
    s32 state;
    char pad2[0x678 - 0x670];
    u8 flag678;
    char pad3[0x67C - 0x679];
    s32 field67C;
    char pad4[0x6AA - 0x680];
    u8 flag6AA;
};

extern "C" void fn_2_23874(Self* self, Scene* scene, s32 arg2) {
    self->scene = scene;
    startKeepScreen__17gfKeepFrameBufferFv((void*)(g_gfApplication + 0xD0));
    while (scene->count != 0) {
        if (scene->count != 0) {
            scene->remove(scene->count - 1);
        }
    }
    if (self->state >= 5 && self->state <= 0x79) {
        self->flag6AA = 1;
    } else {
        self->flag6AA = 0;
    }
    fn_2_24220(self);
    fn_801E9F0C(0);
    self->field67C = arg2;
    self->flag678 = 1;
}
