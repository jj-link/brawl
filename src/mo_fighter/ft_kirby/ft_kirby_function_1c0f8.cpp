#pragma force_active on

struct Triple {
    unsigned int a, b, c;
};

struct Model {
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
    virtual Triple position(int, bool, bool);
};

extern "C" {
extern const char lbl_96_data_608[];
extern const char lbl_96_data_68D8[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_96_E18C(void*, Triple);

void fn_96_1C0F8(void*, char* self) {
    Model* mod = *(Model**)(*(char**)(self + 0xd8) + 0x54);
    const Triple& ret = mod->position(6, false, false);

    void* obj = __dynamic_cast(
        *(void**)(self + 8), 0x3c,
        lbl_96_data_608, lbl_96_data_68D8, 1);

    fn_96_E18C(obj, ret);
}
}
