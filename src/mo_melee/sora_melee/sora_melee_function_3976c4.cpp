#pragma force_active on

extern "C" {
extern unsigned char lbl_27_bss_7B0C[];
extern float lbl_27_rodata_7DB0;
int fn_27_30FACC(void*, unsigned int, int, void*, unsigned int);
}

struct Request {
    int kind;
    bool flag;
    float value;
    int unused;
    bool flag2;
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

struct Modules {
    unsigned char pad[0x3c];
    Target* target;
    unsigned char pad40[0x14];
    Comp* comp;
};

struct Accesser {
    unsigned char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_27_3976C4(void*, Accesser* accesser, int status) {
    switch (fn_27_30FACC(lbl_27_bss_7B0C, 0, status, accesser, 1)) {
    case 0x11b:
    case 0x11c:
    case 0x11d:
    case 0x11e:
    case 0x11f:
    case 0x120:
    case 0x121:
    case 0x122:
    case 0x123:
    case 0x124:
    case 0x125:
    case 0x126:
        return;
    case 0x128: {
        Request request;
        request.kind = 0x16;
        request.flag = false;
        request.value = lbl_27_rodata_7DB0;
        request.flag2 = false;
        accesser->modules->comp->change(0, &request, 0);
        break;
    }
    default:
        if (accesser->modules->comp->query(0) == 1U) {
            accesser->modules->target->call(0, 1);
        }
        break;
    }
}
