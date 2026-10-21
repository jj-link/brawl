#pragma force_active on

typedef unsigned int u32;

struct Work {
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
    virtual bool isFlag(u32);
    virtual void onFlag(u32);
    virtual void offFlag(u32);
};

struct StatusBase {
    char pad[8];
};

struct Status : StatusBase {
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
    virtual void change(int);
};

struct Modules {
    char pad[0x64];
    Work* work;
    char pad2[0x34];
    Status* status;
};

struct Object {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_27_1DF0A0(void*, Object* object) {
    if (object->modules->work->isFlag(0x22000000)) {
        object->modules->work->offFlag(0x22000000);
        object->modules->work->onFlag(0x22000001);
    } else if (object->modules->work->isFlag(0x22000001)) {
        object->modules->work->offFlag(0x22000001);
        Status* status = object->modules->status;
        status->change(1);
    }
}
