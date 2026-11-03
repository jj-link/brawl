#include <types.h>
#pragma force_active on

struct Class_27C_base { char pad[0x3c]; };
class Class_27C : public Class_27C_base {
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
    virtual void fn_6_1134();
    char padding[8];
    int result;
    char padding2[4];
    int state;
};

struct Viewer {
    char pad0[0x124];
    int state;
    char pad1[0x634];
    int value75c;
    int value760;
    int value764;
    int value768;
    unsigned short value76c;
    char pad2[2];
    Class_27C* dialog;
    char pad3[4];
    int value778;
};

extern "C" {
int fn_6_8870(Viewer*, unsigned short*, int*, int*, int);
void fn_6_8DD4(Viewer*, unsigned short, unsigned short);
unsigned short fn_8014E6BC();

int fn_6_9808(Viewer* self) {
    Class_27C* dialog = self->dialog;
    if (dialog->state == 5) {
        int result = dialog->result;
        dialog->fn_6_1134();
        self->dialog = 0;
        if (result == 1)
            return 14;
        int value = fn_6_8870(self, &self->value76c, &self->value764, &self->value768, self->value75c);
        self->value760 = value;
        if (value == 0) {
            self->value778 = 9;
            return 2;
        }
        fn_6_8DD4(self, self->value76c, fn_8014E6BC());
        if (fn_8014E6BC() < self->value76c) {
            self->value778 = 12;
            return 2;
        }
        return 4;
    }
    return self->state;
}
}