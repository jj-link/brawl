#pragma force_active on
extern "C" float lbl_27_rodata_236C;
extern "C" float lbl_27_rodata_2360;

class VBase {
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
    virtual bool v14(int);
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
    virtual void v31(int, float, float);
};

struct Holder {
    char pad[0xa8];
    VBase* sub;
};

struct Owner {
    char pad[0xd8];
    Holder* h;
};

extern "C" void fn_27_17ACD0(void* unused, Owner* obj, int id) {
    if (id == 0x9d) {
        return;
    }
    if (id >= 0x9d || id >= 0x9b || id < 0x97) {
        if (obj->h->sub->v14(0)) {
            obj->h->sub->v31(0, lbl_27_rodata_236C, lbl_27_rodata_2360);
        }
    }
}
