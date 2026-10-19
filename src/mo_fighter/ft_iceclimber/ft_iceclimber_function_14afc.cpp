#pragma force_active on
extern "C" unsigned int fn_27_170720(void* p);

struct Pad {
    int a;
    int b;
};

struct Obj : Pad {
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
    virtual void call(int x);
};

extern "C" void fn_105_14AFC(void* a, char* fighter, void* c) {
    if (fn_27_170720(c) == 1) {
        Obj* obj = *(Obj**)(*(char**)(fighter + 0xd8) + 0x10);
        obj->call(0);
    }
}
