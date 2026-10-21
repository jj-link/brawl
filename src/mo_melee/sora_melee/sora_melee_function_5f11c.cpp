#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Input {
    u8 pad0[8];
    float value8;
    float valueC;
    u8 pad10[0x27];
    u8 flag;
};

class Module {
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
    virtual u32 test(u32, const Input*);
};

struct ObjectBase {
    u8 pad0[8];
};

class Object : public ObjectBase {
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
    virtual Module* getModule();

    u8 padC[0x30];
    u32 field3C;
    u8 pad40[4];
    u8 state[1];
};

extern "C" u32 fn_27_B1468(void*, float, float, u8);

extern "C" bool fn_27_5F11C(Object* self, const Input* input) {
    if (fn_27_B1468(self->state, input->valueC, input->value8, input->flag) == 1) {
        if (self->getModule()->test(self->field3C, input) == 1)
            return true;
    }
    return false;
}
