#pragma force_active on
extern "C" {
void* getTask__6gfTaskFi(int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_27_data_248[];
extern char __RTTI__6gfTask[];
}
struct TaskData {
    char pad[0x3C];
};
struct Task : TaskData {
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
    virtual int first();
    virtual int second();
};
struct Self {
    char pad0[0xC];
    int id;
    char pad1[0x11];
    unsigned char state;
    unsigned char pad2;
    unsigned char enabled;
};
extern "C" int fn_27_19656C(Self* __restrict self) {
    if (self->state != 2) return 0;
    if (self->enabled == 0) return 0;
    void* task = getTask__6gfTaskFi(self->id);
    if (task == 0) return 0;
    Task* object = (Task*)__dynamic_cast(task, 0x3C, lbl_27_data_248, __RTTI__6gfTask, 1);
    if (object->first() != 0) return 0;
    switch (object->second()) {
    case 5:
    case 12:
    case 17:
    case 33:
    case 34:
        break;
    default:
        return 0;
    }
    return 1;
}
