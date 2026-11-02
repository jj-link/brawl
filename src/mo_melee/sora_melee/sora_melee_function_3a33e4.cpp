#include <types.h>
#pragma force_active on

extern "C" float fn_27_192278(void* self, unsigned long arg);

struct gfTask_base {
    char pad[0x3c];
};

class gfTask : public gfTask_base {
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
    virtual void slot39();
    virtual int slot40();
};

struct StateOwner {
    char pad[0x8];
    gfTask* m_task;
};

extern "C" {
int fn_27_3A33E4(void* unused, StateOwner* obj, float f) {
    int state = obj->m_task->slot40();
    if (f <= fn_27_192278(obj, 0xFA5)) {
        if (state == 5) {
            return 0x1250002;
        }
        return 0x24000C;
    }
    if (f >= fn_27_192278(obj, 0xFA6)) {
        if (state == 5) {
            return 0x1250004;
        }
        return 0x24000E;
    }
    if (state == 5) {
        return 0x1250003;
    }
    return 0x24000D;
}
}
