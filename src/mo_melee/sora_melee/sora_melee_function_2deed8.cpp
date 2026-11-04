#pragma force_active on

extern "C" {

struct TaskBase {
    char pad[0x3C];
};

class Task : public TaskBase {
public:
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
    virtual int v40();
};

class Mod {
public:
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
    virtual void v16(void*, int);
};

struct Modules {
    char pad[0x84];
    Mod* mod;
};

struct Object {
    char pad[0x8];
    Task* task;
    char pad2[0xCC];
    Modules* modules;
};

struct Data {
    char pad[0xAC];
    void* f_ac;
    char pad_b0[4];
    void* f_b4;
};

extern void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
extern char g_ftCommonDataAccesser[];

void fn_27_2DEED8(void* a, Object* object) {
    if (object->task->v40() == 2) {
        Data* data = (Data*)getData__20ftCommonDataAccesserCF6ftKind(&g_ftCommonDataAccesser, 2);
        object->modules->mod->v16(data->f_ac, 0);
        object->modules->mod->v16(data->f_b4, 0);
    } else {
        object->modules->mod->v16((void*)0xD, 0);
        object->modules->mod->v16((void*)0xE, 0);
    }
}

} // extern "C"
