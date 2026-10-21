#pragma force_active on

struct StageBase {
    unsigned char padding[0x3C];
};

struct stShadow;

struct Stage : StageBase {
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
    virtual void begin();
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
    virtual int ready();
    virtual void update();

    int state;
    unsigned char padding44[0x80];
    stShadow* shadow;
};

extern "C" {
    extern void* g_GameGlobal;
    extern float lbl_27_data_547E0;
    extern unsigned char lbl_27_data_547E4;
    float fn_8004E94C(void*);
    int fn_8004E958(void*);
    void clearShadowObject__8stShadowFv(stShadow*);
}

extern "C" void processBegin__5StageFv(Stage* self)
{
    lbl_27_data_547E0 = fn_8004E94C(g_GameGlobal);
    lbl_27_data_547E4 = fn_8004E958(g_GameGlobal);

    if (self->shadow) {
        clearShadowObject__8stShadowFv(self->shadow);
    }

    switch (self->state) {
    case 0:
        self->state = 1;
    case 1:
        if (self->ready()) {
            self->begin();
            self->state = 2;
        }
        break;
    case 2:
        break;
    case 3:
        self->state = 4;
        break;
    case 4:
        self->update();
        break;
    }
}
