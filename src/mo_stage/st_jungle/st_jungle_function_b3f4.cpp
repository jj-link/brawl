#pragma force_active on
struct JungleBase {
    unsigned char pad[0x3C];
};

struct Jungle : JungleBase {
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
    virtual void callback(int, int, int);

    unsigned char pad40[0x88];
    unsigned char enabled;
    unsigned char padC9[0x8F];
    int active;
    int argument;
    unsigned char pad160[0x4C];
    int extra;
};

extern "C" void processAnim__6GroundFv(void*);

extern "C" void fn_51_B3F4(Jungle* self) {
    processAnim__6GroundFv(self);
    if (self->enabled && self->active) {
        self->callback(self->argument, 0, self->extra);
    }
}
