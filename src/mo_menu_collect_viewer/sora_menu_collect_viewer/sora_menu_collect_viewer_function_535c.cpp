#pragma force_active on

extern "C" {
void exit__6gfTaskFv(void*);
void* fn_800BF048(int, void*, void*, void*, void*, int, int, int,
                 int, int, int, int);
}

struct Slot {
    void* task;

    void set(void* value) {
        if (task)
            exit__6gfTaskFv(task);
        task = value;
    }
};

struct State {
    char pad[0x1bfc];
    int active;
    char pad2[0x1cfc - 0x1c00];
    Slot slot;
};

struct Viewer {
    char pad[0x3c];

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
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void* getDisplay();
};

extern "C" void fn_6_535C(Viewer* self, void* arg1, void* arg2) {
    void* display = self->getDisplay();

    (*(State**)((char*)self + 0x1ac))->slot.set(
        fn_800BF048(
            0, arg1, arg2,
            (char*)*(State**)((char*)self + 0x1ac) + 0xd0,
            display, 0x1a, 0, 0x2a, 0x2b, 0, 0, 0xf0));

    (*(State**)((char*)self + 0x1ac))->active = 1;
}
