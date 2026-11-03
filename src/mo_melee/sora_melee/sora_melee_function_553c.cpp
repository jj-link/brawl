#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BEA8(void*);
extern void* lbl_27_bss_F0;
}

struct Module;

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(unsigned int state);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual int slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
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
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual unsigned int slot105();
};

class ArgObj {
public:
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void call18(Module* m, int flag);
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void call2C(Module* m);
    virtual void call30(Module* m);
    virtual void s34();
    virtual void s38();
    virtual void s3C();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4C();
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual void call5C(Module* m);
};

struct Obj8_base { char pad[8]; };
class Obj8 : public Obj8_base {
public:
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void call1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void call2C();
    virtual void call30(int v);
    virtual void s34();
    virtual void call38();
    virtual void call3C();
    virtual int call40();
};

struct Field64 {
    char pad[8];
    unsigned int f8;
    unsigned int fC;
};

struct Modules {
    char p00[0x08];
    soNullable* m8;
    char p0c[0x04];
    Obj8* m10;
    char p14[0x30];
    soNullable* m44;
    char p48[0x1c];
    Field64* m64;
    char p68[0x08];
    ArgObj* m70;
    char p74[0x1c];
    soNullable* m90;
    char p94[0x04];
    soNullable* m98;
    Obj8* m9C;
    soNullable* mA0;
    char pA4[0x04];
    soNullable* mA8;
    char pAC[0x08];
    Obj8* mB4;
    Obj8* mB8;
};

struct Module {
    char pad[0xd8];
    Modules* modules;
};

struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_27_4A30();
    virtual void fn_27_4AB8();
    virtual void fn_27_53B8();
    virtual void fn_27_53BC();
    virtual void fn_27_553C_v();
    virtual void fn_27_581C();
    virtual void fn_27_5A78();
    virtual void fn_27_5C04();
    virtual void fn_27_5CA4();
    virtual void processCamera();
    virtual void fn_27_5F38();
    virtual void processEffect();
    virtual void fn_27_6C10();
    virtual void fn_27_60C8();
    virtual void fn_27_60D4();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void fn_27_60CC();
    virtual void fn_27_60D0();
    virtual void init();
    virtual void fn_27_3994();
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
    char pad40[0x20];
    Module* module;
};

extern "C" void fn_27_553C(gfTask* self) {
    Module* module = self->module;
    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
        if (singleton != 0) {
            singleton = fn_27_5BCD0(singleton);
        }
        lbl_27_bss_F0 = singleton;
    }
    unsigned int state = fn_27_5BEA8(lbl_27_bss_F0);
    if (state == 1) {
        int r28 = module->modules->m44->slot9();
        if (r28 == 0) {
            module->modules->m90->slot6();
            module->modules->mA8->slot5();
        }
        if (r28 == 0) {
            module->modules->m98->slot8();
        }
        module->modules->m10->call38();
        self->slot36();
        int r29 = module->modules->mB8->call40();
        if (r28 == 0) {
            module->modules->m8->slot31();
        }
        if (r29 == 0) {
            module->modules->m70->call18(module, 0);
        } else {
            if (module->modules->m8->slot105() == 1U) {
                module->modules->m70->call18(module, 1);
            }
        }
        module->modules->m70->call5C(module);
        if (r28 == 0 && r29 == 0) {
            module->modules->m70->call2C(module);
        }
        module->modules->m64->f8 |= 0x79FC;
        module->modules->m70->call30(module);
        Field64* x = module->modules->m64;
        x->f8 = 0;
        x->fC = 0;
        module->modules->mB4->call1C();
    }
    module->modules->mA0->slot4(state);
    module->modules->m9C->call2C();
    module->modules->m9C->call3C();
    module->modules->m9C->call30(0);
}
