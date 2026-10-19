#pragma force_active on

struct GroundBase {
    char pad0[0x3c];
};

struct GroundVirtual : GroundBase {
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
};

struct Ground : GroundVirtual {
    char pad40[0x7c];
    void* data;
    char padc0[0xe4];
    void* copiedData;
};

extern "C" {
    void fn_40_24E58(Ground*);

    void fn_40_3A21C(Ground* self) {
        fn_40_24E58(self);
        self->v36();
        self->copiedData = self->data;
    }
}
