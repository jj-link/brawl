#pragma force_active on
extern "C" int fn_800B61C0(void*);

struct MenuBase {
    char pad[0x3C];
};

struct Menu : MenuBase {
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
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void activate(void*);

    char pad1[0x1AC - 0x40];
    void* data;

    int selection() const {
        return *(int*)((char*)data + 0x1D40);
    }

    void setReset(int value) {
        *(int*)((char*)data + 0x1BFC) = value;
    }

    void setFlag(int value) {
        *(int*)((char*)data + 0x1BF4) = value;
    }
};

extern "C" void fn_5_14770(Menu* self) {
    if (fn_800B61C0(*(void**)((char*)self->data + 0x16C))) {
        self->activate(*(void**)((char*)self->data + 0x198));
        if (self->selection() < 0) {
            self->setReset(0);
        } else {
            self->setFlag(1);
        }
    }
}
