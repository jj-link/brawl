#pragma force_active on

class Class_6EB8 {
public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void fn_116_DEDC(int);
};

class Class_7624 {
public:
    virtual void a0();
    virtual void a1();
    virtual Class_6EB8** fn_116_11518(int);
    virtual void a3();
    virtual int fn_116_11508();
};

class Work {
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
    virtual void setFloat(float, int);
};

class Other {
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
    virtual void v40(int);
};

struct Modules {
    char pad[0x64];
    Work* work;
    char pad68[0x20];
    Other* other;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_27_12BAF8(void*, int);
extern "C" Class_7624* fn_116_9570(void*);
extern "C" void fn_27_3689A4(void*);
extern "C" void* fn_116_17F48();
extern "C" void fn_27_37263C(void*, void*);

extern "C" void fn_116_17E10(char* self, int arg) {
    int value;
    int i;
    Class_7624* mgr;
    Accesser* accesser = *(Accesser**)(self + 0x60);

    fn_27_12BAF8(self, arg);
    value = *(int*)(self + 0x28);
    mgr = fn_116_9570(self + 0x1630c);

    for (i = 0; i < mgr->fn_116_11508(); i++) {
        (*mgr->fn_116_11518(i))->fn_116_DEDC(value);
    }

    if (arg != 6 && arg != 7) {
        fn_27_3689A4(self + 0x162f4);
    }

    float f = *(float*)(self + 0x16300);
    accesser->modules->work->setFloat(f, 0x11000013);
    f = *(float*)(self + 0x16308);
    accesser->modules->work->setFloat(f, 0x11000014);

    fn_27_37263C(fn_116_17F48(), accesser);
    accesser->modules->other->v40(0x1a);
}
