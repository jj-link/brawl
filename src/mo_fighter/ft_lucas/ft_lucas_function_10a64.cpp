#pragma force_active on

extern "C" {
extern const float lbl_114_rodata_28;
extern const float lbl_114_rodata_2C;
void fn_27_18A0BC(void*, void*);
}

struct Args {
    int unk0;
    float unk4;
    float unk8;
    char unkC[4];
};

struct Module {
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
    virtual float get14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual int get23();
    virtual void v24();
    virtual void v25();
    virtual void set26(float);
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void set32(Args*);
    virtual void v33();
    virtual void v34();
    virtual void set35(int, int, float, float);
};

struct EventModule {
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
    virtual void send(int, void*);
};

extern "C" void fn_114_10A64(void* self, unsigned char* obj) {
    fn_27_18A0BC(self, obj);

    Module* module = *(Module**)(*(unsigned char**)(obj + 0xD8) + 8);
    int status = module->get23();
    float value = module->get14();

    Args args;
    args.unk0 = 0xEA;
    args.unk4 = lbl_114_rodata_28;
    args.unk8 = lbl_114_rodata_2C;
    args.unkC[0] = 0;
    args.unkC[1] = 0;
    args.unkC[2] = 0;
    args.unkC[3] = 0;
    module->set32(&args);

    if ((unsigned int)(status - 0x19) <= 1) {
        module->set35(status, 0, value, lbl_114_rodata_2C);
        module->set26(lbl_114_rodata_2C);
        EventModule* event =
            *(EventModule**)(*(unsigned char**)(obj + 0xD8) + 0x7C);
        event->send(0x4F, obj);
    } else {
        EventModule* event =
            *(EventModule**)(*(unsigned char**)(obj + 0xD8) + 0x7C);
        event->send(0x13, obj);
    }
}
