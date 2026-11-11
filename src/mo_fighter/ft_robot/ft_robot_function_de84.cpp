#pragma force_active on
extern const char lbl_120_data_6F90[];

struct Vec {
    mutable float x, y;
    float z;
};

class Controller {
public:
    unsigned char pad[8];
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
    virtual Vec get(void*);
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void set(void*, const Vec*);
    virtual void v30();
    virtual void v31();
    virtual void* find(const char*);
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float getValue(int);
};

struct Modules {
    unsigned char pad0[4];
    Controller* controller;
    unsigned char pad1[0x5C];
    Object_vptr_0* values;
};

struct Fighter {
    unsigned char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_120_DE84(void*, Fighter* fighter) {
    void* object = fighter->modules->controller->find(lbl_120_data_6F90);
    const Vec& result = fighter->modules->controller->get(object);
    result.x = fighter->modules->values->getValue(0x21000009);
    result.y = fighter->modules->values->getValue(0x21000007);
    fighter->modules->controller->set(object, &result);
}