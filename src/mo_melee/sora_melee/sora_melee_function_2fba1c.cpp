#include <types.h>
#include <so/controller/so_controller_impl.h>

#pragma force_active on

struct Owner;

struct Msg {
    int id;
    float a, b;
    u8 c[4];
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3(int = 0, Owner* = 0);
    virtual int slot4(int);
    virtual void slot5(int, int);
    virtual void slot6();
    virtual void slot7(int);
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
    virtual void slot30(Msg*, float);
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual int slot38();
};

struct Object_vptr_3c_base {
    char pad[0x3c];
};

class Object_vptr_3c : public Object_vptr_3c_base {
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
    virtual int slot40();
};

class Other {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
};

struct Holder {
    char pad0[8];
    Object_vptr_0* a;
    char pad1[8];
    Other* b;
    char pad2[0x44];
    Object_vptr_0* controller;
    char gap[4];
    Object_vptr_0* work;
    char pad3[8];
    Object_vptr_0* status;
};

struct Owner {
    char pad0[8];
    Object_vptr_3c* kind;
    char pad1[0xcc];
    Holder* h;
};

struct Data {
    int value;
    int pad;
    float limit;
};

extern "C" {
    extern int g_ftCommonDataAccesser;
    extern int lbl_27_bss_7B0C;
    extern int lbl_27_data_2D7E0;
    extern int __RTTI__18soControllerModule;
    extern float lbl_27_rodata_6520;
    extern float lbl_27_rodata_6524;
    extern const double lbl_27_rodata_6528;

    Data* fn_27_1492A4(void*, int);
    int fn_27_30FA2C(void*, int, int, Owner*, int);
    void* __dynamic_cast(void*, long, const void*, const void*, long);
}

extern "C" void fn_27_2FBA1C(void*, Owner* self) {
    Data* data = fn_27_1492A4(&g_ftCommonDataAccesser, self->kind->slot40());
    Object_vptr_0* status = self->h->status;
    int state = self->h->b->slot3();

    self->h->work->slot7(0x10000042);
    if ((float)self->h->work->slot4(0x10000042) > data->limit) {
        self->h->work->slot5(0, 0x10000042);
        self->h->work->slot7(0x10000041);
        int limit = data->value;
        if (self->h->work->slot4(0x10000041) >= limit) {
            self->h->work->slot5(limit, 0x10000041);
            if (!state) {
                status->slot3(
                    fn_27_30FA2C(&lbl_27_bss_7B0C, 0, 0x119, self, 0),
                    self
                );
                return;
            }
        }
    }

    if (!state) {
        __dynamic_cast(
            self->h->controller, 0, &lbl_27_data_2D7E0,
            &__RTTI__18soControllerModule, 1
        );

        Object_vptr_0* controller = self->h->controller;
        int mask = soController::getButtonMask(soController::Pad_Button_Special);
        int buttons = controller->slot38();
        if ((buttons & mask) != 0) {
            Msg msg;
            msg.id = 0x1ce;
            msg.a = lbl_27_rodata_6520;
            msg.b = lbl_27_rodata_6524;
            msg.c[0] = 0;
            msg.c[1] = 0;
            msg.c[2] = 0;
            msg.c[3] = 0;
            self->h->a->slot30(&msg, lbl_27_rodata_6520);
            status->slot3(
                fn_27_30FA2C(&lbl_27_bss_7B0C, 0, 0x11a, self, 0),
                self
            );
        } else {
            controller = self->h->controller;
            mask = soController::getButtonMask(soController::Pad_Button_Guard);
            int buttons2 = controller->slot38();
            if ((buttons2 & mask) != 0) {
                status->slot3(0x1a, self);
            }
        }
    }
}
