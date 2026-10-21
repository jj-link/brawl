#pragma force_active on

struct Prefix {
    char padding[0x3C];
};

struct Object : Prefix {
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
    virtual void update();

    char padding40[8];
    unsigned char b48;
    unsigned char b49;
    unsigned char b4A;
    unsigned char b4B;
    unsigned char b4C;
    unsigned char b4D;
};

extern "C" {
extern unsigned int lbl_27_bss_59C0;
void fn_27_254CE8(void (*func)(void*));
void* getInstance__8ipSwitchFv();
void fn_8004A914(void*, int);

bool fn_27_2552B0(Object* self) {
    if (self->b49 != 0 && lbl_27_bss_59C0 != 0) {
        self->update();
        if (self->b4B == 0 && self->b4D == 0) {
            return false;
        }
        fn_27_254CE8(0);
        self->b48 = 0;
        self->b49 = 0;
    }
    fn_8004A914(getInstance__8ipSwitchFv(), 0);
    return true;
}
}
