#pragma force_active on

struct Mod {
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
    virtual void slot13(int, int, int);
    virtual unsigned int slot14(int);
    virtual void v15();
    virtual void v16();
    virtual unsigned int slot17(unsigned int);
};

struct Modules {
    unsigned char p0[0x24];
    Mod* m24;
    unsigned char p1[0x64 - 0x28];
    Mod* m64;
    unsigned char p2[0xA8 - 0x68];
    Mod* mA8;
};

struct Accesser {
    unsigned char pad[0xD8];
    Modules* modules;
};

struct Fighter {
    unsigned char p0[0x60];
    Accesser* acc;
    unsigned char p1[0x1A384 - 0x64];
    unsigned char flag;
};

extern "C" void fn_27_12E7C8(void*);

extern "C" void fn_121_96B8(Fighter* self) {
    Accesser* acc = self->acc;
    fn_27_12E7C8(self);
    if (self->flag == 0) {
        if (acc->modules->m64->slot17(0x12000041) == 1U) {
            if (acc->modules->mA8->slot14(0) == 0U) {
                if (acc->modules->m64->slot17(0x12000035) == 0U) {
                    acc->modules->m24->slot13(0, 1, 1);
                }
                self->flag = 1;
            }
        }
    } else {
        if (acc->modules->m64->slot17(0x12000041) == 0U ||
            acc->modules->mA8->slot14(0) == 1U) {
            acc->modules->m24->slot13(0, 0, 1);
            self->flag = 0;
        }
    }
}
