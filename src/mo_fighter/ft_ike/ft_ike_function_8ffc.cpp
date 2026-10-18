#pragma force_active on
typedef unsigned int u32;

struct Task {
    char pad[0x28];
    u32 id;
};

struct Event {
    char data[0x20];
};

struct ObjectBase {
    char pad[0x3c];
};

struct Object : ObjectBase {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual u32 kind();
};

struct Link {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual int test(int, u32);
    virtual void mid0();
    virtual void mid1();
    virtual void mid2();
    virtual void end(int);
    virtual void tail0();
    virtual void tail1();
    virtual void tail2();
    virtual void tail3();
    virtual void tail4();
    virtual void tail5();
    virtual void send(int, Event*);
};

struct Modules {
    char pad[0x54];
    Link* link;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
void* getInstance__15gfTaskSchedulerFv();
Task* getTask__15gfTaskSchedulerFQ26gfTask8CategoryUl(void*, int, u32);
void fn_119_89FC(Event*, int, int);
extern char lbl_119_data_1E14[];
extern char lbl_119_data_1F14[];
void* __dynamic_cast(void*, long, const void*, const void*, short);

void fn_119_8FFC(Task* self, Access* access) {
    u32 i = 0;
    Task* task = getTask__15gfTaskSchedulerFQ26gfTask8CategoryUl(
        getInstance__15gfTaskSchedulerFv(), 10, 0);

    Event event;
    fn_119_89FC(&event, 42, -1);

    while (task) {
        Object* object = (Object*)__dynamic_cast(
            task, 0x3c, lbl_119_data_1E14, lbl_119_data_1F14, 0);

        if (object && object->kind() == 1 &&
            task->id != 0xffffffff && task->id != self->id) {
            Link* link = access->modules->link;
            if (link->test(6, task->id)) {
                link = access->modules->link;
                link->send(6, &event);
                link = access->modules->link;
                link->end(6);
            }
        }

        ++i;
        task = getTask__15gfTaskSchedulerFQ26gfTask8CategoryUl(
            getInstance__15gfTaskSchedulerFv(), 10, i);
    }
}
}
