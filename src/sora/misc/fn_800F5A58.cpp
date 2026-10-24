#pragma force_active on
extern "C" void fn_80075F1C(void*, int, int);
extern "C" void* g_sndSystem;

struct Base {
    char pad[0x3C];
};

struct Self : Base {
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
    virtual void v27(int);
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    char pad2[0x48];
    int state;
    char pad3[0x390];
    int sound;
};

extern "C" void fn_800F5A58(Self* self) {
    if (self->sound >= 0) {
        fn_80075F1C(g_sndSystem, self->sound, 0);
        self->sound = -1;
    }
    if (self->state == 1) {
        self->v27(0);
    } else if (self->state >= 2 && self->state < 6) {
        self->v36();
    }
}
