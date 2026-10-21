#pragma force_active on

struct Actor;

struct Status {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void change(int, Actor*);
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
    virtual int current();
};

struct Ground {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int test();
};

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int get(unsigned int);
};

struct Pad8 {
    int a, b;
};

struct Input : Pad8 {
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
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual int test(float, int);
};

struct Modules {
    char pad0[0x10];
    Input* input;
    Ground* ground;
    char pad1[0x4c];
    Work* work;
    char pad2[8];
    Status* status;
};

struct Actor {
    char pad[0xd8];
    Modules* modules;
};

extern float lbl_27_rodata_25EC;
extern float lbl_27_rodata_25F0;

extern "C" void fn_27_18E690(void*, Actor* actor) {
    if (actor->modules->status->current() == 0x7d) {
        if (actor->modules->ground->test() == 0) {
            if (actor->modules->input->test(lbl_27_rodata_25EC, 0) == 0 &&
                (actor->modules->input->test(lbl_27_rodata_25F0, 0) == 0 ||
                 actor->modules->work->get(0x20000000) > 0x78)) {
                actor->modules->status->change(0, actor);
            }
        }
    }
}
