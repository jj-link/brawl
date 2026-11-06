#pragma force_active on

typedef unsigned int u32;
typedef unsigned char u8;

struct Work {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int get(int);
    virtual void set(int, int);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void add(int, int);
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void on(int);
};

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

struct Self {
    char pad[0x60];
    Access* access;
};

struct Event {
    char pad[0xc];
    u32 id;
    char pad2[0x11];
    u8 flag;
};

struct Task {
    char pad[0x2c];
    u32 w;
};

struct DynObj {
    char pad[0x8c0];
    int state;
};

extern "C" {
void* getInstance__15gfTaskSchedulerFv();
Task* getTask__15gfTaskSchedulerFUl(void*, u32);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_119_data_D4[];
extern char lbl_119_data_1F14[];
void fn_27_135EDC(void*, Event*, void*);

void fn_119_7FAC(Self* self, Event* ev, void* arg2) {
    if (self->access->modules->status->kind() == 0x11b && ev->flag == 1) {
        Task* task = getTask__15gfTaskSchedulerFUl(
            getInstance__15gfTaskSchedulerFv(), ev->id);

        if (((int)((task->w << 17) & 0xff800000) >> 24) == 0xb) {
            DynObj* obj = (DynObj*)__dynamic_cast(
                task, 0x3c, lbl_119_data_D4, lbl_119_data_1F14, 0);
            if (obj->state == 0x31 || obj->state == 0x4f) {
                self->access->modules->work->on(0x22000013);
            }
        } else {
            self->access->modules->work->on(0x22000013);
        }
    }
    fn_27_135EDC(self, ev, arg2);
}
}
