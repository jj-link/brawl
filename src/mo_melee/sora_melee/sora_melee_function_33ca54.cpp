#pragma force_active on

typedef unsigned int u32;

struct Module {
    char pad[0x3C];
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
    virtual int getFirst();
    virtual int getSecond();
};

struct Status {
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
    virtual void change(int, int);
};

struct Modules {
    char pad[0x84];
    Status* status;
};

struct Accesser {
    char pad0[8];
    Module* module;
    char pad1[0xCC];
    Modules* modules;
};

extern "C" {
extern unsigned char lbl_27_bss_7B0C[];
int fn_27_30FACC(void*, u32, int, void*, u32);

void fn_27_33CA54(void*, Accesser* accesser, int status) {
    int first = accesser->module->getFirst();
    int second = accesser->module->getSecond();

    if (first == 0 && (second == 14 || second == 5)) {
        int result = fn_27_30FACC(
            lbl_27_bss_7B0C, 0, status, accesser, 1);

        switch (result) {
        default:
            if ((u32)(result - 0x117) > 2U)
                break;
        case 0x112:
            return;
        }

        Status* target = accesser->modules->status;
        if (second == 14) {
            target->change(1, 0);
        } else if (second == 5) {
            target->change(14, 0);
        }
    }
}
}
