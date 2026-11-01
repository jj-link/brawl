#pragma force_active on
extern "C" {
extern unsigned char lbl_27_bss_7B0C[];
extern unsigned char g_ftCommonDataAccesser[];
int fn_27_30FACC(void*, unsigned int, int, void*, unsigned int);
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
}

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void set(int, unsigned long);
};

struct Motion {
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
    virtual void change(int);
};

struct Fighter {
    unsigned char pad[0x3c];
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual int f40();
};

struct Modules {
    unsigned char pad[0x64];
    Work* work;
    unsigned char pad2[0x1c];
    Motion* motion;
    Status* status;
};

struct Accesser {
    unsigned char pad[8];
    Fighter* fighter;
    unsigned char pad2[0xcc];
    Modules* modules;
};

extern "C" void fn_27_2FB704(void*, Accesser* accesser, int status) {
    switch (fn_27_30FACC(lbl_27_bss_7B0C, 0, status, accesser, 1)) {
    case 0x118:
    case 0x11a:
    case 0x11b:
        break;
    default:
        accesser->modules->work->set(0, 0x10000041);
        Fighter* fighter = accesser->fighter;
        int motion;
        if (fighter->f40() == 5) {
            motion = 13;
        } else {
            motion = *(int*)((unsigned char*)getData__20ftCommonDataAccesserCF6ftKind(g_ftCommonDataAccesser, 3) + 0x98);
        }
        accesser->modules->motion->change(motion, 0);
        accesser->modules->status->change(26);
        break;
    }
}
