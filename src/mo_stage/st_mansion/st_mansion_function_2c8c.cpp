#pragma force_active on
struct Parameters {
    unsigned char pad00[0x20];
    float value0;
    float value1;
    unsigned char pad28[0x38];
    float scale0;
    float scale1;
    float scale2;
};

struct MansionBase {
    unsigned char pad00[0x3C];

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
    virtual Parameters* getParameters();
};

struct Mansion : MansionBase {
    unsigned char pad40[0x11C];
    float value;
    unsigned char mode;
    unsigned char pad161[0x4F];
    unsigned char enabled;
};

struct GameInfo {
    unsigned char pad00[8];
    unsigned char type : 6;
    unsigned char other : 2;
    unsigned char pad09[5];
    unsigned char scale : 3;
    unsigned char rest : 5;
};

struct GameGlobal {
    unsigned char pad00[8];
    GameInfo* info;
};

extern "C" GameGlobal* g_GameGlobal;

extern "C" void fn_47_2C8C(Mansion* self) {
    Parameters* p = self->getParameters();
    if (p) {
        switch (self->mode) {
        case 0:
            self->value = p->value0;
            break;
        case 1:
            self->value = p->value1;
            break;
        }

        if (self->enabled == 1) {
            GameInfo* info = g_GameGlobal->info;
            if (info && info->type == 7) {
                switch (info->scale) {
                case 0:
                    self->value *= p->scale0;
                    break;
                case 1:
                    self->value *= p->scale1;
                    break;
                case 2:
                    self->value *= p->scale2;
                    break;
                }
            }
        }
    }
}
