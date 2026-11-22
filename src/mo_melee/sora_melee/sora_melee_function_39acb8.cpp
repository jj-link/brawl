#include <types.h>
#pragma force_active on

class TimerModule {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int get(unsigned long);
    virtual void put(int, unsigned long);
};

class StateModule {
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
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual int slot18(int);
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void* slot24(int);
};

struct CharacterBase {
    char pad[0x3c];
};

class Character : public CharacterBase {
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
    virtual int slot40();
};

struct Modules {
    char pad0[0x64];
    TimerModule* timer;
    char pad1[0x1c];
    StateModule* state;
};

struct Access {
    char pad0[8];
    Character* character;
    char pad1[0xcc];
    Modules* modules;
};

extern "C" {
extern signed char lbl_27_bss_8964;
extern char lbl_27_bss_8968[];
extern void* __vt__10soNullable;
extern char lbl_27_bss_8958[];
extern char lbl_27_data_9B6C0[];
extern char lbl_27_data_C938[];
extern char lbl_27_data_9B790[];
void* fn_27_39A934(void*, int);
void* __register_global_object(void*, void*, void*);
void* __dynamic_cast(void*, long, const void*, const void*, long);
int fn_27_39FA04(void*);
int fn_27_1922CC(Access*, int);
int fn_27_39B4DC(Access*, int, int*);
void fn_27_39B58C(Access*);
void fn_27_39B758(Access*);
}

static inline void initGlobal() {
    if (lbl_27_bss_8964 == 0) {
        *(void**)lbl_27_bss_8968 = &__vt__10soNullable;
        *(void**)lbl_27_bss_8968 = lbl_27_data_9B790;
        __register_global_object(lbl_27_bss_8968, (void*)fn_27_39A934, lbl_27_bss_8958);
        lbl_27_bss_8964 = 1;
    }
}

extern "C" void fn_27_39ACB8(Access* self) {
    TimerModule* timer = self->modules->timer;
    int val = timer->get(0x10000042);
    int result = -1;
    int arg = 0;
    StateModule* state = self->modules->state;
    if (self->character->slot40() == 5) {
        arg = 0xd;
    }
    void* p;
    if (state->slot18(arg) != 0 && (p = state->slot24(arg)) != 0) {
        result = fn_27_39FA04(__dynamic_cast(p, 0, lbl_27_data_9B6C0, lbl_27_data_C938, 1));
    } else {
        initGlobal();
        int sp8;
        if (fn_27_39B4DC(self, 0, &sp8) != 0) {
            result = sp8;
        }
    }
    if (val != result) {
        if (result >= fn_27_1922CC(self, 0x5dc0)) {
            initGlobal();
            fn_27_39B58C(self);
        } else {
            initGlobal();
            fn_27_39B758(self);
        }
    }
    timer->put(result, 0x10000042);
    timer->put(result, 0x10000041);
}
