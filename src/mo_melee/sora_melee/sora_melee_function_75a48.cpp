#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void* getInstance__15gfTaskSchedulerFv();
extern "C" void* getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(void*, int, unsigned long);
extern "C" const char lbl_27_data_248[];
extern "C" const char __RTTI__6gfTask[];

class Task {
    char pad[0x3c];

public:
    virtual int v0() = 0;
    virtual int v1() = 0;
    virtual int v2() = 0;
    virtual int v3() = 0;
    virtual int v4() = 0;
    virtual int v5() = 0;
    virtual int v6() = 0;
    virtual int v7() = 0;
    virtual int v8() = 0;
    virtual int v9() = 0;
    virtual int v10() = 0;
    virtual int v11() = 0;
    virtual int v12() = 0;
    virtual int v13() = 0;
    virtual int v14() = 0;
    virtual int v15() = 0;
    virtual int v16() = 0;
    virtual int v17() = 0;
    virtual int v18() = 0;
    virtual int v19() = 0;
    virtual int v20() = 0;
    virtual int v21() = 0;
    virtual int v22() = 0;
    virtual int v23() = 0;
    virtual int v24() = 0;
    virtual int v25() = 0;
    virtual int v26() = 0;
    virtual int v27() = 0;
    virtual int v28() = 0;
    virtual int v29() = 0;
    virtual int v30() = 0;
    virtual int v31() = 0;
    virtual int v32() = 0;
    virtual int v33() = 0;
    virtual int v34() = 0;
    virtual int v35() = 0;
    virtual int v36() = 0;
    virtual int v37() = 0;
    virtual int v38() = 0;
    virtual int v39() = 0;
};

struct Owner {
    char pad0[0x7f];
    bool enabled;
    char pad1[0xc];
    unsigned long taskId;
    char pad2[0x12];
    unsigned char category;
};

extern "C" int fn_27_75A48(Owner* __restrict self, unsigned long* __restrict arg1) {
    if (self->enabled == 0 || self->taskId == 0xFFFFFFFFUL) {
        return 0;
    }

    void* sched = getInstance__15gfTaskSchedulerFv();
    if (sched == 0) {
        return 0;
    }

    void* task = getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(
        sched, self->category, self->taskId);
    Task* p = (Task*)__dynamic_cast(
        task, 0x3c, lbl_27_data_248, __RTTI__6gfTask, 0);
    if (p == 0) {
        return 0;
    }

    return (*arg1 & (1 << p->v39())) != 0;
}
