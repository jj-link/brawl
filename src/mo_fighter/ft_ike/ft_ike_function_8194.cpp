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

struct Target {
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
    virtual int test(int);
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

struct Vec {
    float x, y, z;
};

extern "C" {
void* getInstance__15gfTaskSchedulerFv();
Task* getTask__15gfTaskSchedulerFUl(void*, u32);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_119_data_1598[];
extern char lbl_119_data_1F14[];
Target* fn_27_14D490(void*);
void fn_119_8C5C(Vec*, Access*);
void fn_119_8DBC(Access*, Vec*);

void fn_119_8194(void*, Event* ev, Access* acc) {
    if (acc->modules->status->kind() == 0x116 ||
        acc->modules->status->kind() == 0x124 ||
        acc->modules->status->kind() == 0x126) {
        Task* task = getTask__15gfTaskSchedulerFUl(
            getInstance__15gfTaskSchedulerFv(), ev->id);

        if (((int)((task->w << 17) & 0xff800000) >> 24) == 10 &&
            ev->flag == 1) {
            void* obj = __dynamic_cast(
                task, 0x3c, lbl_119_data_1598, lbl_119_data_1F14, 1);

            if (fn_27_14D490(obj)->test(0) == 0) {
                acc->modules->work->on(0x22000011);
                acc->modules->work->on(0x22000014);

                if (acc->modules->work->get(0x20000001) == 0) {
                    Vec vec;
                    fn_119_8C5C(&vec, acc);
                    fn_119_8DBC(acc, &vec);
                }

                if (acc->modules->work->get(0x20000001) < 6) {
                    Work* work = acc->modules->work;
                    work->set(
                        ev->id, work->get(0x20000001) + 0x20000002);
                    acc->modules->work->add(1, 0x20000001);
                }
            }
        }
    }
}
}
