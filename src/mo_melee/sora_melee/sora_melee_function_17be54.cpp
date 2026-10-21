#pragma force_active on

class SoundModule {
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
    virtual void play(int, int);
};

class WorkModule {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int get(int);
};

class StatusModule {
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
    virtual void change(int, int);
};

struct Modules {
    char pad0[0x50];
    SoundModule* sound;
    char pad54[0x10];
    WorkModule* work;
    char pad68[0x40];
    StatusModule* status;
};

struct Object {
    char pad[0xD8];
    Modules* modules;
};

extern "C" int fn_27_193590(Object*, int);
extern "C" void fn_27_17B26C(void*, Object*, int);
extern "C" void fn_27_17EC40(Object*, int);

extern "C" void fn_27_17BE54(void* a, Object* b, int c) {
    if (fn_27_193590(b, c) == 0) {
        fn_27_17B26C(a, b, 2);
        b->modules->sound->play(0x1F93, 0);
        if (b->modules->work->get(0x2000000C) == 2) {
            b->modules->status->change(
                b->modules->work->get(0x2000000E), 0);
        }
    }
    fn_27_17EC40(b, c);
}
