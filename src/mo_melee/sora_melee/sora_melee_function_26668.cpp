#pragma force_active on
typedef unsigned int u32;

struct Scheduler {
    u32 flags;
};

extern "C" Scheduler* getInstance__15gfTaskSchedulerFv();

struct Owner;

struct ObjectBase {
    char pad[8];
};

struct Object : ObjectBase {
    virtual void v0();
    virtual void v1();
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
    virtual void callback(void*);

    char padC[0x24];
    int active;
    char pad34[0x20];
    Owner* owner;
};

struct TargetBase {
    char pad[0x3C];
};

struct Target : TargetBase {
    virtual void v0();
    virtual void v1();
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
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void callback(Owner*);
};

struct Owner {
    char pad[8];
    Target* target;
};

extern "C" void fn_27_26668(Object* self, void* arg, int mode) {
    if (mode == 1) {
        if (self->active != 0) {
            self->callback(arg);
        }
    } else if (mode == 0) {
        if (((int)((getInstance__15gfTaskSchedulerFv()->flags << 8) &
                   0xFF800000U) >> 24) <= 1 ||
            ((int)((getInstance__15gfTaskSchedulerFv()->flags << 8) &
                   0xFF800000U) >> 24) >= 6) {
            Owner* owner = self->owner;
            owner->target->callback(owner);
        }
    }
}
