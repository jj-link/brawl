#pragma force_active on
extern "C" void fn_27_1DB0F0(void*, void*, void*, void*, int);
extern "C" int randi__Fl(int);

struct Module {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void f5(int, void*);
    virtual int f6(int);
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
    virtual int f18();
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
    virtual void f34(int);
};

struct Dev {
    char pad0[0xC];
    Module* m0C;
    char pad10[0x54];
    Module* m64;
    char pad68[0x8];
    Module* m70;
};

struct Accesser {
    char pad0[0xD8];
    Dev* dev;
};

struct Self {
    char pad0[0x60];
    Accesser* acc;
};

struct Event {
    int kind;
    int pad4;
    int value;
};

struct Table3x2 {
    int v[3][2];
};

struct Pair2 {
    int v[2];
};

extern const Table3x2 lbl_120_rodata_A0;
extern const Pair2 lbl_120_rodata_B8;

extern "C" void fn_120_181F4(Self* self, Event* event, Accesser* accesser, void* sender, int link)
{
    if (accesser->dev->m70->f18() != 3) {
        switch (event->kind) {
        case 0x838:
            self->acc->dev->m70->f5(3, accesser);
            break;
        case 0x839: {
            int r26 = accesser->dev->m70->f18();
            int var = 0;
            if (accesser->dev->m64->f6(0x20000000) > 2) {
                Table3x2 table = lbl_120_rodata_A0;
                int idx = randi__Fl(2);
                var = table.v[r26][idx];
            } else if (accesser->dev->m64->f6(0x20000000) > 1) {
                Pair2 pair = lbl_120_rodata_B8;
                var = pair.v[randi__Fl(2)];
            }
            event->value = var;
            accesser->dev->m70->f5(var, accesser);
            accesser->dev->m0C->f34(0);
            break;
        }
        }
    }
    fn_27_1DB0F0(self, event, accesser, sender, link);
}
