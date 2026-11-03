#include <ft/ft_manager.h>
#include <if/if_mngr.h>
#pragma force_active on

class TaskView : public gfTask {
public:
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual bool slot26();
};

struct EntryByte { unsigned char value; };
struct Entry { char pad[0x5c]; };
struct Data { char pad[0x9a]; };

class ObserverView {
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
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual bool slot43();
    char pad08[8];
    unsigned char* data;
    char pad10[0x20];
    TaskView* task;
    unsigned char : 2;
    unsigned char flags : 1;
};

extern "C" void fn_800E14A4(void*, int, int);

extern "C" void fn_27_27D6A4(ObserverView* self, int entryId, int value) {
    int playerNo = g_ftManager->getPlayerNo(entryId);
    if (self->slot43() && !((self->data[0xB] >> 1) & 1) && self->flags &&
        (!self->task || !self->task->slot26()) && playerNo >= 0) {
        unsigned char* m = (unsigned char*)g_IfMngr;
        unsigned char index = *((unsigned char*)((Entry*)self->data + playerNo) + 0x9a);
        fn_800E14A4(*(void**)(m + *((unsigned char*)((EntryByte*)m + index) + 0x68) * 4 + 0x4c), value, 1);
    }
}
