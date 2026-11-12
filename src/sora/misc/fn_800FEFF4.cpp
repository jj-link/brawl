#pragma force_active on

extern "C" {

struct Entry {
    void (*fn0)(void*);
    int (*fn1)(void*);
};

extern const Entry lbl_804091B8[];

class Obj {
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
    virtual void v13(void*);
};

struct Res {
    char pad[0x10];
    void* unk10;
};

struct Self {
    Obj* obj;
    char pad[0x64];
    Res* res;
    char pad2[0xA4];
    int state;
    char pad3;
    unsigned char flag;
};

int fn_800B61C0(void*);

void fn_800FEFF4(Self* self) {
        Res* res;
    const Entry* table = lbl_804091B8;
    int old = self->state;
    if (table[old].fn1) {
        int ret = table[old].fn1(self);
        if (ret != old) {
            self->state = ret;
            if (table[ret].fn0) {
                table[ret].fn0(self);
            }
        }
    }
    if (self->flag != 0) {
        res = self->res;
        if (fn_800B61C0(res)) {
            self->obj->v13(res->unk10);
            self->flag = 0;
        }
    }
}

}
