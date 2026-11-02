#pragma force_active on

extern "C" {
extern unsigned char lbl_27_bss_7B0C[];
int fn_27_30FACC(void*, unsigned int, int, void*, unsigned int);
}

struct Request {
    int kind;
    bool flag;
};

struct Target {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void call(int, int);
};

struct Comp {
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
    virtual unsigned int query(int);
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void change(int, Request*, int);
};

struct Other {
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
    virtual void call(int);
};

struct Modules {
    unsigned char pad[0x20];
    Other* other;
    unsigned char pad24[0x18];
    Target* target;
    unsigned char pad40[0x14];
    Comp* comp;
};

struct Accesser {
    unsigned char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_27_397F7C(void*, Accesser* accesser, int status) {
    switch (fn_27_30FACC(lbl_27_bss_7B0C, 0, status, accesser, 1)) {
    case 0x11b:
    case 0x121:
        if (accesser->modules->comp->query(0) == 1U) {
            Request request;
            request.kind = 0x13;
            request.flag = false;
            accesser->modules->comp->change(0, &request, 0);
        }
        break;
    case 0x11a:
        return;
    default:
        if (accesser->modules->comp->query(0) == 1U) {
            accesser->modules->target->call(0, 1);
        }
        accesser->modules->other->call(0);
        break;
    }
}
