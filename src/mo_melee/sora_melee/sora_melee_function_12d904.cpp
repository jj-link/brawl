#include <so/so_value_accesser.h>
#include <so/so_module_accesser.h>

#pragma force_active on

class Object_vptr_c;

#define MODULE_VTABLE(SLOT3, SLOT19, SLOT21) \
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3 SLOT3; \
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); \
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); \
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); \
    virtual void slot16(); virtual unsigned int slot17(unsigned int); virtual void slot18(); \
    virtual void slot19 SLOT19; virtual void slot20(); virtual void slot21 SLOT21; \
    virtual void slot22(); virtual void slot23(); virtual void slot24(int); virtual void slot25(); \
    virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29(); \
    virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33(); \
    virtual void slot34(); virtual void slot35(); virtual void slot36(int, int)

class Object_vptr_0 { public: MODULE_VTABLE((int, int, int), (int), (int, int, int)); };
class Object_vptr_effect { public: MODULE_VTABLE((), (int, int), (int)); };

class SlowBase { public: char pad[8]; };
class SlowModule : public SlowBase {
public:
    MODULE_VTABLE((int, int, int), (int), (int, int, int));
};

class Object_vptr_c_base { public: char pad[12]; };
class Object_vptr_c : public Object_vptr_c_base {
public:
    virtual void slot0(); virtual int slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16();
};

class FighterBase { public: char pad[0x3c]; };
class FighterView : public FighterBase {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
    virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43();
    virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void slot47();
    virtual void slot48(); virtual void slot49(); virtual void slot50(); virtual void slot51();
    virtual void slot52(); virtual void slot53(); virtual void slot54(); virtual void slot55();
    virtual void slot56(); virtual void slot57(); virtual void slot58(); virtual void slot59();
    virtual void slot60(); virtual void slot61(); virtual void slot62(); virtual void slot63();
    virtual void slot64(); virtual void slot65(); virtual void slot66(); virtual void slot67();
    virtual void slot68(); virtual void slot69(); virtual void slot70(); virtual void slot71();
    virtual void slot72(); virtual void slot73(); virtual void slot74(); virtual void slot75();
    virtual void slot76(); virtual void slot77(); virtual void slot78(); virtual void slot79();
    virtual void slot80(); virtual void slot81(); virtual void slot82(); virtual void slot83();
    virtual void slot84(); virtual void slot85(); virtual void slot86(); virtual void slot87();
    virtual void slot88(); virtual void slot89(); virtual void slot90(); virtual void slot91();
    virtual void slot92(); virtual void slot93(); virtual void slot94(); virtual void slot95();
    virtual void slot96(); virtual void slot97(); virtual void slot98(); virtual void slot99();
    virtual void slot100(); virtual void slot101(); virtual void slot102(); virtual void slot103();
    virtual void slot104(); virtual void slot105(); virtual void slot106(); virtual void slot107();
    virtual void slot108(); virtual void slot109(); virtual void slot110(); virtual void slot111();
    virtual void slot112(); virtual void slot113(); virtual void slot114(); virtual void slot115();
    virtual void slot116(); virtual void slot117(); virtual void slot118(); virtual void slot119();
    virtual void slot120(); virtual void slot121(); virtual void slot122(); virtual void slot123();
    virtual void slot124(); virtual void slot125(); virtual void slot126(); virtual void slot127();
    virtual void slot128(); virtual void slot129(); virtual void slot130(); virtual void slot131();
    virtual void slot132(); virtual void slot133(); virtual void slot134(); virtual void slot135();
    virtual void slot136(); virtual void slot137(); virtual void slot138(); virtual void slot139();
    virtual void slot140(); virtual void slot141(); virtual void slot142(); virtual void slot143();
    virtual void slot144(); virtual void slot145(); virtual void slot146(); virtual void slot147();
    virtual void slot148(); virtual void slot149(); virtual void slot150(); virtual void slot151();
    virtual void slot152(); virtual void slot153(); virtual void slot154(); virtual void slot155();
    virtual void slot156(); virtual void slot157(); virtual void slot158(); virtual void slot159();
    virtual void slot160(); virtual void slot161(); virtual void slot162(); virtual void slot163();
    virtual void slot164(); virtual void slot165(); virtual void slot166(); virtual void slot167();
    virtual void slot168(); virtual void slot169(); virtual void slot170(); virtual void slot171();
    virtual void slot172(); virtual void slot173(); virtual void slot174(); virtual void slot175();
    virtual void slot176(); virtual void slot177(int, int, float);
    virtual void slot178(); virtual void slot179(); virtual void slot180(); virtual void slot181();
    virtual void slot182(); virtual void slot183(); virtual void slot184();
    virtual Object_vptr_c* slot185();
    virtual unsigned int slot186();
    virtual void slot187(); virtual void slot188();
};

struct Self : FighterView {
    char pad40[0x20];
    soValueAccesser* accesser;
    char pad64[0xa8];
    int field10c;
};

struct ModuleBlock {
    char pad0[0x50];
    Object_vptr_effect* sound;
    Object_vptr_0* link;
    Object_vptr_0* visibility;
    Object_vptr_0* controller;
    Object_vptr_0* camera;
    Object_vptr_0* work;
    char pad68[0x20];
    Object_vptr_effect* effect;
    char pad8c[0x2c];
    SlowModule* slow;
};

extern "C" {
unsigned int fn_27_111E60(Object_vptr_c*);
unsigned int fn_27_111E00(Object_vptr_c*);
unsigned int fn_27_111EC0(Object_vptr_c*);
void fn_27_1595AC(void*);
void fn_27_1599DC(void*);
void fn_27_10D8F8(void*, unsigned int, int);
void setCurry__7FighterFbi(void*, bool, int);
void fn_27_1392D4(Self*, int, int, int, float, float);
int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned int, unsigned int);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned int, unsigned int);
extern void* g_ftManager;
extern const unsigned char lbl_27_rodata_1E18[];
extern const float lbl_27_rodata_1048;
extern const float lbl_27_rodata_1058;
}

extern "C" void fn_27_12D904(Self* self, unsigned int arg1, unsigned int arg2, int arg3) {
    soValueAccesser* accesser = self->accesser;
#define MODULES (*(ModuleBlock**)((char*)accesser + 0xd8))

    if (MODULES->work->slot17(0x12000006) == 1) {
        Object_vptr_c* owner = self->slot185();

        if (MODULES->work->slot17(0x12000007) == 1)
            fn_27_1595AC((char*)self + 0x13c);

        MODULES->work->slot19(0x12000008);
        MODULES->work->slot19(0x12000007);
        MODULES->work->slot19(0x12000006);
        MODULES->work->slot19(0x1200001e);
        self->slot157();

        if (arg1 == 1) {
            MODULES->visibility->slot3(0, -1, 1);
            MODULES->effect->slot21(8);

            if (MODULES->work->slot17(0x1200000a) == 1 &&
                arg2 == 1 &&
                fn_27_111E60(owner) == 0) {
                MODULES->effect->slot19(0x53, 8);
            }

            int value = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
                (soModuleAccesser*)accesser, 0x5a1a, 0);
            MODULES->effect->slot36(0, value);
            MODULES->camera->slot22();
            fn_27_1599DC((char*)self + 0x13c);
            MODULES->slow->slot16();
        }

        if (lbl_27_rodata_1E18[self->slot186()] & 4)
            MODULES->sound->slot19(0xdb, 0);

        fn_27_10D8F8(g_ftManager, (unsigned int)self->field10c, arg3);

        if (arg2 == 1) {
            if (owner->slot1() == 0 && fn_27_111E60(owner) == 1)
                setCurry__7FighterFbi(self, true, -1);

            if (fn_27_111E00(owner) == 1)
                self->slot177(1, -1, lbl_27_rodata_1058);

            if (fn_27_111EC0(owner) == 1) {
                float a = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                    (soModuleAccesser*)accesser, 0xd88, 0);
                float b = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                    (soModuleAccesser*)accesser, 0xd86, 0);
                float c = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                    (soModuleAccesser*)accesser, 0xd89, 0);
                float ratio = (c - b) / a;

                fn_27_1392D4(self, 1, 1, 0, lbl_27_rodata_1048, ratio);
            }
        }
    }
#undef MODULES
}

#undef MODULE_VTABLE
