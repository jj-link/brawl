#pragma force_active on

extern "C" {

struct ResultBase {
    char pad0[0x0C];
    int field_c;
    char pad1[0x0C];
};

struct ResultObj : ResultBase {
    virtual void v0();
    virtual void v1();
    virtual int validate(void*, void*);
    char pad2[0x08];
    int field_28;
    char pad3[0x5C];
    unsigned char field_88;
    unsigned char field_89;
};

struct KindObject {
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
    virtual ResultObj* getResult();
};

struct Arg1Struct {
    char pad0[0x10];
    int counter;
    char pad1[0x0C];
    KindObject** ptr_20;
    char pad2[0x78];
    struct FinalObject* final;
};

struct Arg2Struct {
    char pad[0x08];
    unsigned int flags;
    char pad2[0x16];
    unsigned char field_22;
};

struct FinalObject {
    virtual void submit(Arg1Struct*, ResultObj*);
};

struct Arg0Struct {
    char pad0[0x0C];
    int field_c;
    int field_10;
    char pad1[0xA8];
    Arg1Struct* field_bc;
    int field_c0;
    int field_c4;
    short field_c8;
    char pad2[2];
    int field_cc;
    int field_d0;
    short field_d4;
    char pad3[2];
    unsigned short field_d8;
};

void fn_801650B0(void*, void*, void*);
void fn_8015BFB4(void*, void*, int, void*);

int fn_80165370(Arg0Struct* self, Arg1Struct* arg1, Arg2Struct* arg2, signed char arg3) {
    self->field_10 = 0;
    self->field_c = 1;
    self->field_c0 = 0;
    self->field_c8 = 0;
    self->field_c4 = 0;
    self->field_cc = 0;
    self->field_d4 = 0;
    self->field_d0 = 0;
    self->field_d8 = 0;

    fn_801650B0(self, arg2, arg1);
    self->field_bc = arg1;

    ResultObj* result = (*arg1->ptr_20)->getResult();
    if (result == 0) {
        return 0;
    }

    if (result->validate(self, arg2) == 0) {
        return 0;
    }

    Arg1Struct* parent = self->field_bc;
    int old = parent->counter;
    parent->counter = old + 1;
    fn_8015BFB4(&self->field_c0, result, old, parent);
    self->field_d8++;

    result->field_c = 1;
    result->field_28 = 0;

    if (arg2->flags & 0x20) {
        result->field_28 |= 1;
    }
    if (arg2->flags & 0x40) {
        result->field_28 |= 2;
    }

    result->field_88 = arg2->field_22;
    result->field_89 = (unsigned char)arg3;
    self->field_bc->final->submit(self->field_bc, result);
    return 1;
}

}
