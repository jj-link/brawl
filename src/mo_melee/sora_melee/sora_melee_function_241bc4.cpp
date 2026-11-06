#pragma force_active on
typedef unsigned char u8;

struct StageData {
    char pad[0x620];
    int value;
};

struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void processDefault();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void processPreMapCorrection();
    virtual void slot5();
    virtual void slot6();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void slot12();
    virtual void processEffect();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
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
    virtual int slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48(StageData*);
    virtual int slot49();

    int pad40;
    u8 state;
    u8 pad45;
    u8 enabled;
    u8 flag;
    char pad48[0x6c - 0x48];
    int value;
    StageData* data;
};

extern Object_vptr_3c* lbl_27_bss_5668;

extern "C" void fn_27_241BC4(Object_vptr_3c* self) {
    if (self->enabled != 0) {
        Object_vptr_3c* stage = lbl_27_bss_5668;
        switch ((int)self->state) {
        case 0:
            if (self->flag == 1) {
                self->state = 6;
                return;
            }
            if (stage != 0)
                self->state = 1;
            break;
        case 1:
            if (self->flag == 1) {
                self->state = 5;
                return;
            }
            if (stage != 0) {
                StageData* data = self->data;
                self->value = data->value;
                stage->slot48(data);
                self->state = 2;
            }
            break;
        case 2:
            if (stage->slot49() != 0)
                self->state = 3;
            break;
        case 3:
            if (self->slot38() != 0)
                self->state = 5;
            break;
        case 5:
            if (self->flag == 1)
                self->state = 6;
            else
                self->state = 0;
            break;
        }
    }
}
