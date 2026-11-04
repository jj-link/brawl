#include <types.h>
#include <snd/snd_system.h>
#include <ft/ft_manager.h>
#include <so/so_external_value_accesser.h>
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
    virtual void fn_27_1DC8C();
    virtual void fn_27_1D638();
    virtual void fn_27_1D800();
    virtual void fn_27_1D9C8();
    virtual void fn_27_1DAF8();
    virtual void fn_27_1D37C(int, int, int);
};

struct Thresholds {
    char pad[0x24];
    int low;
    int high;
    char pad2[0x10];
    int limit;
    float extra;
};

struct State {
    char pad[0x44];
    Thresholds* thresholds;
    char pad48[0xc];
    int owner;
    char pad58[8];
    int field60;
    int count;
    char pad68[8];
    int sound;
    char pad74[4];
    int soundArg;
    char pad7c;
    unsigned char flag;
};

struct Global {
    char pad[0x64];
    float value;
};

extern Global* lbl_805A0360;
extern "C" u32 fn_27_10A848(void*, int, int);
extern "C" u32 fn_80077DA0(sndSystem*, int);
extern "C" void fn_80075F1C(sndSystem*, int, int);

extern "C" void fn_27_110098(State* self) {
    int prevOwner;
    Global* g;
    int savedCount = self->count;
    u32 found = 0;
    int i;
    int entryId;

    self->count = 0;
    i = 0;
    g = lbl_805A0360;
    for (; i < g_ftManager->getEntryCount(); i++) {
        entryId = g_ftManager->getEntryIdFromIndex(i);
        if (g_ftManager->isFighterActivate(entryId, -1) == 1 && fn_27_10A848(g_ftManager, entryId, -1) == 1U) {
            Vec3f pos = soExternalValueAccesser::getPos(g_ftManager->getFighter(entryId, -1));
            if (pos.m_y < g->value + self->thresholds->extra) {
                self->count = self->count + 1;
            } else if (entryId == self->owner) {
                found = 1;
            }
        }
    }

    Thresholds* thr = self->thresholds;
    if (savedCount < thr->limit && self->count >= thr->limit) {
        if (found == 1U) {
            prevOwner = self->owner;
            if (self->sound != -1 && fn_80077DA0(g_sndSystem, self->sound) == 1U) {
                fn_80075F1C(g_sndSystem, self->sound, 0);
            }
            self->sound = -1;
            self->sound = g_sndSystem->playSE((SndID)0x17, self->soundArg, 0, 0, -1);
            if (prevOwner != -1) {
                if (self->owner == prevOwner) {
                    if (self->field60 < self->thresholds->high && self->field60 >= self->thresholds->low) {
                        self->flag = 1;
                    }
                }
                ((Class_1768*)g_ftManager->getOwner(prevOwner))->fn_27_1D37C(1, 60, 0);
            }
        } else {
            if (self->sound != -1 && fn_80077DA0(g_sndSystem, self->sound) == 1U) {
                fn_80075F1C(g_sndSystem, self->sound, 0);
            }
            self->sound = -1;
            self->sound = g_sndSystem->playSE((SndID)0x17, self->soundArg, 0, 0, -1);
        }
    }
}
