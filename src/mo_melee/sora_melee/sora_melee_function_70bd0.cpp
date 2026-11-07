#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void* slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(void* p);
    virtual void slot13();
    virtual void slot14();
    virtual float slot15();
    virtual void slot16();
    virtual unsigned slot17();
    virtual void slot18();
};

struct Inner {
    char pad[0x8];
    Object_vptr_0* m_8;
};

struct Outer {
    char pad[0xd8];
    Inner* m_d8;
};

struct acCmdInterpreterStackData {
    int kind;
    int intData;
    char boolData;
    char pad[3];
    void* addressData;
    float floatData;
};

class acCmdInterpreter {
public:
    char pad[0x24];
    float m_24;
    char pad28[0x1c];
    Outer* m_44;
    char pad48[4];
    void* m_4c;

    Object_vptr_0* getCurrentCmd();
    void pushSystemStack(const acCmdInterpreterStackData& d);
};

extern "C" void fn_27_70BD0(acCmdInterpreter* self) {
    if (self->m_44 != 0) {
        Object_vptr_0* cmd = self->getCurrentCmd();
        if (self->m_4c != cmd->slot7()) {
            if (self->m_44->m_d8->m_8->slot17() == 1) return;
            float f24 = self->m_24;
            if (f24 >= self->m_44->m_d8->m_8->slot15()) return;
        }
        void* addr = cmd->slot7();
        float f2 = self->m_44->m_d8->m_8->slot12(self->m_44);
        acCmdInterpreterStackData d;
        d.kind = 8;
        d.intData = 0;
        d.boolData = 1;
        d.addressData = addr;
        d.floatData = f2;
        self->pushSystemStack(d);
    }
}