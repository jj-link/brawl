#pragma force_active on
#include <so/so_module_accesser.h>

struct State {
    int a;
    unsigned char b;
    int mode;
    int id;
    Vec3f out;
};
struct Local {
    int a, b;
    Vec3f p, q;
};
extern "C" void fn_121_100DC(State*);
extern "C" void fn_121_10BEC(void*, Vec3f*, Vec3f*);
extern "C" int fn_121_1031C(void*);
extern const float lbl_121_rodata_6C;

class Class_8E20 {
public:
    virtual void fn_121_22F8();
    virtual void fn_121_12B5C();
    virtual void fn_121_14840();
    virtual void fn_121_14838();
    virtual void fn_121_14830();
    virtual void fn_121_14828();
    virtual void fn_121_14820();
    virtual void fn_121_14818();
    virtual void fn_121_14810();
    virtual void fn_121_14808();
    virtual void fn_121_14800();
    virtual int fn_121_147F8(unsigned int, int, Vec3f*, Vec3f*, float, int, int, int);
    virtual void fn_121_147F0();
    virtual void fn_121_147E8();
    virtual void fn_121_14798();
    virtual void fn_121_147E0();
    virtual void fn_121_147D0();
    virtual void fn_121_147C0();
    virtual void fn_121_147B0();
};

extern "C" void fn_121_1018C(void*, soModuleAccesser* self) {
    soWorkManageModule* work = &self->getWorkManageModule();
    if (!self->getStopModule().isStop()) {
        State state;
        fn_121_100DC(&state);
        state.mode = 2;
        self->getLinkModule().sendEventNodes(0, reinterpret_cast<soLinkEventArgs&>(state), 0u);
        work->onFlag(0x22000011);
        soWorkManageModule* work2 = &self->getWorkManageModule();
        if (work2->getInt(0x20000001) == 0) {
            Class_8E20* effect = reinterpret_cast<Class_8E20*>(&self->getEffectModule());
            Local loc;
            fn_121_10BEC(self, &loc.p, &loc.q);
            loc.a = -1;
            int result = effect->fn_121_147F8(0xE30002, 0, &loc.p, &loc.q, lbl_121_rodata_6C, 1, 0, 0);
            work2->setInt(result, 0x20000001);
        }
        if (fn_121_1031C(self)) {
            self->getStatusModule().changeStatusRequest(0x11B, self);
            self->getKineticModule().clearSpeedAll();
        }
    }
}
