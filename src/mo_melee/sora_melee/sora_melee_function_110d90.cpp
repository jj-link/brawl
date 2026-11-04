#include <types.h>
#include <snd/snd_system.h>
#include <ft/ft_manager.h>
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

struct Class_8398_base { char pad[0xc]; };
class Class_8398 : public Class_8398_base {
public:
    virtual void fn_27_734D4();
    virtual void fn_27_72E78();
    virtual void fn_27_72E88();
    virtual void fn_27_72DB0();
    virtual void fn_27_7354C();
    virtual void fn_27_72D70();
    virtual void fn_27_72F8C();
    virtual void fn_27_7313C();
    virtual void fn_27_7348C();
    virtual void fn_27_72E98();
    virtual void fn_27_73048();
    virtual void fn_27_731F8();
    virtual void fn_27_73310();
    virtual void fn_27_72E38();
};

struct Class_13380_base { char pad[0xc]; };
class Class_13380 : public Class_13380_base {
public:
    virtual void fn_27_893E8();
    virtual void fn_27_88D8C();
    virtual void fn_27_88D9C();
    virtual void fn_27_88CC4();
    virtual void fn_27_89460();
    virtual void fn_27_88C84();
    virtual void fn_27_88EA0();
    virtual void fn_27_89050();
    virtual void fn_27_893A0();
    virtual void fn_27_88DAC();
    virtual void fn_27_88F5C();
    virtual void fn_27_8910C();
    virtual void fn_27_89224();
    virtual void fn_27_88D4C();
};

struct Class_270C0_base { char pad[0xc]; };
class Class_270C0 : public Class_270C0_base {
public:
    virtual void fn_27_11110C();
    virtual void fn_27_112FEC();
    virtual void fn_27_1113B8();
    virtual void fn_27_111850();
    virtual void fn_27_111894();
    virtual void fn_27_1118A0();
    virtual void fn_27_1118E4();
    virtual void fn_27_111A14();
    virtual void fn_27_110FC8();
    virtual void fn_27_111AB8();
    virtual void fn_27_112E78();
    virtual void fn_27_112E94();
    virtual void fn_27_112EB0();
    virtual void fn_27_112ECC();
};

struct Class_87E68_base { char pad[0xc]; };
class Class_87E68 : public Class_87E68_base {
public:
    virtual void fn_27_32952C();
    virtual void fn_27_328EB0();
    virtual void fn_27_754A0();
    virtual void fn_27_328F10();
    virtual void fn_27_73EF8();
    virtual void fn_27_73FA4();
    virtual void fn_27_74050();
    virtual void fn_27_740FC();
    virtual void fn_27_741A8();
    virtual void fn_27_7426C();
    virtual void fn_27_74330();
    virtual void fn_27_74404();
    virtual void fn_27_744B0();
    virtual void fn_27_749F0();
};

struct Class_8F1F0_base { char pad[0xc]; };
class Class_8F1F0 : public Class_8F1F0_base {
public:
    virtual void fn_27_356774();
    virtual void fn_27_356100();
    virtual void fn_27_754A0();
    virtual void fn_27_356160();
    virtual void fn_27_73EF8();
    virtual void fn_27_73FA4();
    virtual void fn_27_74050();
    virtual void fn_27_740FC();
    virtual void fn_27_741A8();
    virtual void fn_27_7426C();
    virtual void fn_27_74330();
    virtual void fn_27_74404();
    virtual void fn_27_744B0();
    virtual void fn_27_749F0();
};

struct Thresholds {
    char pad[0x24];
    int low;
    int high;
    char pad2[4];
    float first;
    float second;
    float third;
};

struct State {
    char pad[0x44];
    Thresholds* thresholds;
    char pad48[0xc];
    int owner;
    char pad58[8];
    int count;
    char pad64[0xc];
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

struct SoundEntry { int a; int b; SndID id; };
extern Global* lbl_805A0360;
extern const SoundEntry lbl_27_rodata_F18[3];
extern "C" u32 fn_80077DA0(sndSystem*, int);
extern "C" void fn_80075F1C(sndSystem*, int, int);

extern "C" int fn_27_110D90(State* self, int owner, float value) {
    float base = lbl_805A0360->value;
    Thresholds* thresholds;
    if (value > base) {
        goto rejected;
    }
    thresholds = self->thresholds;
    if (value < base + thresholds->third) {
    rejected:
        return 0;
    }
    int index;
    if (value > base + thresholds->first) {
        index = 2;
    } else {
        index = value > base + thresholds->second;
    }
    if (index == -1) {
        return 0;
    }
    if (self->sound != -1 && fn_80077DA0(g_sndSystem, self->sound) == 1U) {
        fn_80075F1C(g_sndSystem, self->sound, 0);
    }
    self->sound = -1;
    self->sound = g_sndSystem->playSE(lbl_27_rodata_F18[index].id, self->soundArg, 0, 0, -1);
    if (owner != -1) {
        if (self->owner == owner) {
            Thresholds* t = self->thresholds;
            int count = self->count;
            if (count < t->high && count >= t->low) {
                self->flag = 1;
            }
        }
        ((Class_1768*)g_ftManager->getOwner(owner))->fn_27_1D37C(1, 60, 0);
    }
    return 1;
}
