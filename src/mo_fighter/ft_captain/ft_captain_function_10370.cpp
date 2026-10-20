#pragma force_active on
typedef unsigned int u32;

struct TaskObject {
    char pad0[0x28];
    u32 id;
    char pad1[0x8c];
    int kind;
};

struct MotionModule {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void set(int);
    virtual void v8();
    virtual int test();
};

struct Modules {
    char pad[0x58];
    MotionModule* motion;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct SavedTasks {
    u32 count;
    u32 ids[1];
};

extern "C" {
void* getInstance__15gfTaskSchedulerFv();
void* getTask__15gfTaskSchedulerFQ26gfTask8CategoryUl(void*, int, u32);
void* __dynamic_cast(void*, long, const void*, const void*, short);
Access* getModuleAccesser__23soExternalValueAccesserFP11StageObject(TaskObject*);
extern char lbl_100_data_167C[];
extern char lbl_100_data_22AC[];
extern SavedTasks* lbl_100_bss_2D0;

void fn_100_10370() {
    MotionModule* motion;
    u32 i;
    TaskObject* object;
    void* task = getTask__15gfTaskSchedulerFQ26gfTask8CategoryUl(
        getInstance__15gfTaskSchedulerFv(), 12, i = 0);

    while (task) {
        object = (TaskObject*)__dynamic_cast(
            task, 0x3c, lbl_100_data_167C, lbl_100_data_22AC, 0);

        if (object->kind != 0x8e) {
            motion = getModuleAccesser__23soExternalValueAccesserFP11StageObject(
                object)->modules->motion;
            if (motion->test()) {
                lbl_100_bss_2D0->ids[lbl_100_bss_2D0->count] = object->id;
                ++lbl_100_bss_2D0->count;
                motion->set(0);
            }
        }

        task = getTask__15gfTaskSchedulerFQ26gfTask8CategoryUl(
            getInstance__15gfTaskSchedulerFv(), 12, ++i);
    }
}
}
