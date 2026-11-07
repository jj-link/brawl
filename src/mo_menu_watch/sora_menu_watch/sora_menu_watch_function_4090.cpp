#include <snd/snd_system.h>
#pragma force_active on
class Base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual float getFrame();
};
struct Inner { char pad[0xc]; Base* base; };
struct Obj { char pad[0x14]; Inner* inner; };
struct Self { char pad[0x8c]; Obj* obj; char pad2[0x504-0x90]; int result; };
extern "C" int fn_800B5328(Obj*);
extern "C" float lbl_15_rodata_1C8;
extern "C" int fn_15_4090(Self* self) {
    Obj* obj = self->obj;
    if (lbl_15_rodata_1C8 == obj->inner->base->getFrame()) {
        g_sndSystem->playSE((SndID)0x1efb, -1, 0, 0, -1);
    }
    float frame = obj->inner->base->getFrame();
    if (frame >= (float)(fn_800B5328(obj) - 15)) {
        return 5;
    }
    return self->result;
}