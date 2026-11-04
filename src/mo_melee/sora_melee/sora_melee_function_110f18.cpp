#include <ft/ft_manager.h>
#include <snd/snd_system.h>

#pragma force_active on

struct Class_1768_base { char pad[0xc]; };
class Class_1768 : public Class_1768_base {
public:
    virtual void fn_27_1DCD4();
    virtual void fn_27_1D618();
    virtual void fn_27_1D628();
    virtual void fn_27_1D384();
    virtual void fn_27_1B5E0();
    virtual void fn_27_1CC24();
    virtual void fn_27_1D744();
    virtual void fn_27_1D90C();
    virtual int fn_27_1DC8C();
};

struct State {
    char pad[0x68];
    int sound;
    char pad6c[0xc];
    int soundArg;
};

extern "C" u32 fn_80077DA0(sndSystem*, int);
extern "C" void fn_80075F1C(sndSystem*, int, int);

extern "C" void fn_27_110F18(State* self, int owner) {
    if (((Class_1768*)g_ftManager->getOwner(owner))->fn_27_1DC8C() > 0) {
        if (self->sound != -1 && fn_80077DA0(g_sndSystem, self->sound) == 1U) {
            fn_80075F1C(g_sndSystem, self->sound, 0);
        }
        self->sound = -1;
        self->sound = g_sndSystem->playSE((SndID)0x1a, self->soundArg, 0, 0, -1);
    }
}