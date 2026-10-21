#pragma force_active on

struct Base {
    virtual Base* v0();
    virtual Base* v1();
    virtual Base* v2();
    virtual Base* v3();
    virtual Base* v4();
    virtual Base* v5();
    virtual Base* v6();
    virtual Base* v7();
    virtual Base* v8();
    virtual Base* v9();
    virtual Base* v10();
    virtual Base* v11();
    virtual Base* v12();
    virtual Base* v13();
    virtual Base* v14();
    virtual Base* v15();
    virtual Base* v16();
    virtual Base* v17();
    virtual Base* v18();
    virtual Base* v19();
    virtual Base* v20();
    virtual Base* v21();
    virtual Base* v22();
    virtual Base* v23();
    virtual Base* v24();
    virtual Base* v25();
    virtual Base* v26();
    virtual Base* v27();
    virtual Base* v28();
    virtual Base* v29();
    virtual Base* v30();
    virtual Base* v31();
    virtual Base* v32();
    virtual Base* v33();
    virtual Base* v34();
    virtual Base* v35();
    virtual Base* v36();
    virtual Base* v37();
    virtual Base* v38();
    virtual Base* v39();
    virtual Base* v40();
    virtual Base* v41();
    virtual int v42(int);
};

struct Sub8 {
    unsigned char pad[8];
    virtual void v0();
    virtual void v1();
    virtual Base* v2();
    virtual void v3();
    virtual Base* v4();
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
    virtual Base* v15();
};

struct Mod {
    Sub8* a0;
    char p0[0x18 - 4];
    Base* a18;
    char p1[0x54 - 0x1c];
    Base* a54;
};

struct Node {
    char p0[0x28];
    int taskId;
};

struct Accesser {
    char p0[8];
    Node* node;
    char p1[0xd8 - 0xc];
    Mod* mod;
};

extern "C" int fn_105_1E844(void*, int, int, int, int);

extern "C" int fn_105_C1D0(void* self, Accesser* acc) {
    Base* r31;
    Sub8* r30;
    int taskId;
    int r28 = acc->mod->a54->v42(6);
    r30 = acc->mod->a0;
    taskId = acc->node->taskId;
    r31 = acc->mod->a18->v2()->v2();
    Base* r5 = r30->v4()->v15();
    fn_105_1E844(self, taskId, (int)r5, (int)r31, r28);
    return 1;
}
