#include <types.h>
#include <snd/snd_system.h>
#include <ft/ft_manager.h>
#pragma force_active on

struct Object_vptr_c_base { char pad[0xc]; };
class Object_vptr_c : public Object_vptr_c_base {
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
    virtual void slot13(int, int, int);
};

struct Thresholds {
    float levels[3];
    char pad[0x18];
    int low;
    int high;
};

struct Object_vptr_3c_base {
    char pad[0x3c];
};
class State : public Object_vptr_3c_base {
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
    virtual void processCamera();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual u32 slot42();

    char pad40[4];
    Thresholds* thresholds; // 0x44
    char pad48[0xc];
    int owner;      // 0x54
    char pad58[8];
    int count;      // 0x60
    char pad64[0xc];
    int sound;      // 0x70
    char pad74[4];
    int soundArg;   // 0x78
    char pad7c;
    unsigned char flag; // 0x7d
};

struct SoundEntry { int a; int b; SndID id; };
extern const SoundEntry lbl_27_rodata_F18[3];
extern "C" u32 fn_80077DA0(sndSystem*, int);
extern "C" void fn_80075F1C(sndSystem*, int, int);

extern "C" int fn_27_110BDC(State* self, int owner, float unused, float value) {
    if (self->slot42() == 1) {
        int index;
        Thresholds* t = self->thresholds;
        if (value >= t->levels[2]) {
            index = 2;
        } else if (value >= t->levels[1]) {
            index = 1;
        } else {
            index = value >= t->levels[0] ? 0 : -1;
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
                Thresholds* th = self->thresholds;
                int count = self->count;
                if (count < th->high && count >= th->low) {
                    self->flag = 1;
                }
            }
            ((Object_vptr_c*)g_ftManager->getOwner(owner))->slot13(1, 60, 0);
        }
        return 1;
    }
    return 0;
}
