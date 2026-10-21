#pragma force_active on

extern "C" int fn_27_1DA24C();

class Owner {
    unsigned char padding[0x3c];

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
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual int accept(signed char);
};

class Actor {
public:
    virtual void v0();
    virtual signed char v1();
    virtual signed char v2();
};

extern "C" int fn_27_2EDC70(Owner* self, Actor* actor) {
    if (fn_27_1DA24C() != 0) {
        return 1;
    }

    if (self->accept(actor->v1()) == 0) {
        return 0;
    }

    if (actor->v2() > -1) {
        actor->v2();
    }

    return 0;
}
