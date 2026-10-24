#pragma force_active on
struct Msg { int id; unsigned char flag; };
struct Module {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void call(int, Msg*, int);
};
struct Other {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void call(int, int);
};
struct Modules {
    char pad[0x54];
    Module* status;
    char pad58[0x2c];
    Other* other;
};
struct Accesser {
    char pad[0xd8];
    Modules* modules;
};
extern "C" unsigned char lbl_27_bss_7B0C[];
extern "C" int fn_27_30FACC(void*, unsigned int, int, void*, unsigned int);
extern "C" void fn_27_364150(void*, int status, void*, void*, Accesser* accesser) {
    switch (fn_27_30FACC(lbl_27_bss_7B0C, 0, status, accesser, 1)) {
    case 0x10c:
    case 0x112:
    case 0x117:
    case 0x118:
        return;
    case 0x119: {
        Msg msg;
        msg.id = 0x838;
        msg.flag = 0;
        accesser->modules->status->call(1, &msg, 0);
        break;
    }
    case 0x11a: {
        Msg msg;
        msg.id = 0x839;
        msg.flag = 0;
        accesser->modules->status->call(1, &msg, 0);
        break;
    }
    default:
        accesser->modules->other->call(13, 0);
        break;
    }
}
