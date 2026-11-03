#pragma force_active on

typedef unsigned int u32;
typedef int s32;

struct WorkNoFloat {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 isFlag(u32);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void setFlag(u32, void*);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void doSomething(u32, void*);
};

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 isFlag(u32);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void setFlag(u32, void*, float);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void doSomething(u32, void*);
};

struct Status {
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
    virtual void change(s32);
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual s32 check(s32);
    virtual void v46();
    virtual void clear(s32);
    virtual void v48();
    virtual void v49();
    virtual float getValue(s32);
};

struct ObjA8 {
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
    virtual void fn44(s32);
};

struct Modules {
    char pad[0x08];
    Status* status;
    char pad2[0x58];
    Work* work;
    char pad3[0x40];
    ObjA8* obja8;
};

struct Object {
    char pad[0xD8];
    Modules* modules;
};

extern "C" float lbl_27_rodata_23D0;

extern "C" void fn_27_17F224(void*, Object* self, s32 arg) {
    s32 flag = 0;
    u32 base = 0x20000000;
    if (self->modules->work->isFlag(base + 1) == arg ||
        self->modules->work->isFlag(base + 2) == arg ||
        self->modules->work->isFlag(base + 4) == arg ||
        self->modules->work->isFlag(base + 3) == arg ||
        self->modules->work->isFlag(base + 5) == arg ||
        self->modules->work->isFlag(base + 6) == arg ||
        self->modules->work->isFlag(base + 7) == arg ||
        self->modules->work->isFlag(base + 0xA) == arg ||
        self->modules->work->isFlag(base + 0xB) == arg ||
        self->modules->work->isFlag(base + 8) == arg ||
        self->modules->work->isFlag(base + 9) == arg) {
        flag = 1;
    }
    if (flag) {
        float f = lbl_27_rodata_23D0;
        if (self->modules->status->check(1) != -1) {
            f = self->modules->status->getValue(1);
            self->modules->status->clear(1);
            reinterpret_cast<WorkNoFloat*>(self->modules->work)->setFlag(0x21000007, self->modules);
        }
        self->modules->work->setFlag(0x21000006, self->modules, f);
        s32 flag2 = (self->modules->work->isFlag(base + 8) == arg ||
                     self->modules->work->isFlag(base + 9) == arg);
        if (flag2) {
            self->modules->status->change(1);
        }
        self->modules->work->doSomething(0x2200000A, self->modules);
    } else {
        self->modules->status->change(1);
        self->modules->obja8->fn44(0);
    }
}