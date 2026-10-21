#pragma force_active on
extern const float lbl_27_rodata_320;

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int count();
};

struct Base {
    int a;
    int b;
};

class Self : public Base {
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
    virtual void v17(int);
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
    virtual void v39(int);
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
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58(int, float);

    char pad[0x34 - 0x0C];
    Obj* obj;
};

extern "C" void fn_27_10994(Self* self) {
    self->v17(0);
    self->v39(3);
    int n = self->obj->count();
    for (int i = 0; i < n; i++) {
        self->v58(i, lbl_27_rodata_320);
    }
}
