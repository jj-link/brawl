#pragma force_active on

typedef unsigned int u32;

struct Status {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual int kind();
};

struct Work {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void on(u32);
};

struct ObjectBase {
    char pad[0x3c];
};

struct Object : ObjectBase {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual int kind();
};

struct Modules {
    char pad[0x64];
    Work* work;
    char pad2[8];
    Status* status;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct Fighter {
    char pad[0x60];
    Access* access;
};

struct Event {
    char pad[0xc];
    u32 id;
};

extern "C" {
void fn_27_135EDC(void*, void*);
void* getInstance__15gfTaskSchedulerFv();
void* getTask__15gfTaskSchedulerFUl(void*, u32);
void* __dynamic_cast(void*, long, const void*, const void*, short);

extern char lbl_122_data_8C98[];
extern char lbl_122_data_8D98[];

void fn_122_DC1C(Fighter* self, Event* event) {
    fn_27_135EDC(self, event);
    if (self->access->modules->status->kind() == 0x11a && event != 0) {
        Object* object = (Object*)__dynamic_cast(
            getTask__15gfTaskSchedulerFUl(
                getInstance__15gfTaskSchedulerFv(), event->id),
            0x3c, lbl_122_data_8C98, lbl_122_data_8D98, 0);

        if (object != 0 && object->kind() != 2 && object->kind() != 3) {
            self->access->modules->work->on(0x22000010);
        }
    }
}
}
