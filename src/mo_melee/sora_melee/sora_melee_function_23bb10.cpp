#pragma force_active on

typedef unsigned char u8;

struct Data {
    u8 id;
    u8 kind;
    u8 pad02[3];
    u8 value;
    u8 pad06[0x15];
    u8 flags1B;
    u8 pad1C;
    u8 flags1D;
};

struct Object {
    u8 pad00[0x3C];

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
    virtual Data* getData();

    u8 pad40[4];
    u8 state;
    u8 pad45[2];
    u8 flag47;
    u8 pad48[0xD];
    u8 value55;
    u8 value56;
    u8 pad57[3];
    u8 id5A;
    u8 value5B;
};

extern "C" void fn_27_23BB10(Object* self) {
    u8 state = self->state;
    if (state == 3 || (u8)(state + 0xF8) <= 1U) {
        Data* data = self->getData();
        if (data->kind != 3 && data->id == self->id5A) {
            data = self->getData();
            u8 flags = data->flags1D;
            u8 value = data->value;

            if ((flags >> 4U) & 1) {
                value = 0xC;
            } else if ((flags >> 3U) & 1) {
                value = 0xD;
            }

            if ((data->flags1B >> 2U) & 1) {
                value |= 0x80;
            }

            if (self->value5B == value &&
                self->value55 == self->value56 &&
                self->flag47 != 1) {
                goto unchanged;
            }
        }

        self->state = 5;
        return;

unchanged:
        self->state = 7;
    }
}
