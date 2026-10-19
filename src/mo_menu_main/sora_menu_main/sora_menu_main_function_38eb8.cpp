#pragma force_active on
struct TaskBase {
    char padding0[0x3C];
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
    virtual void close();
};

struct Task : TaskBase {
    char padding40[8];
    int result;
    int padding4C;
    int state;
};

struct Menu {
    char padding0[0x128];
    int selection;
    char padding12C[0xC];
    int state;
    char padding13C[0xA8];
    Task* task;
};

extern "C" {
extern void* g_muWifiInterfaceTask;
void fn_800C753C();

int fn_2_38EB8(Menu* self) {
    if (self->task->state != 5)
        return self->state;

    int result = self->task->result;
    self->task->close();
    self->task = 0;

    int next;
    if (result == 1) {
        self->selection = 3;
        next = 11;
        if (g_muWifiInterfaceTask)
            fn_800C753C();
    } else {
        next = 2;
    }
    return next;
}
}
