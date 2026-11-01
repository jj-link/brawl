#pragma force_active on

struct Base {
    char pad[0x3c];
};

struct Earth : Base {
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
    virtual void v27(int);

    char pad1[0x110];
    unsigned char state;
    char pad2[7];
    unsigned char* ptr;
};

extern "C" void fn_66_13808(Earth* self) {
    switch (self->state) {
        case 0:
            self->v27(0);
            self->state = 11;
            return;
        case 10:
            self->state = 11;
            return;
        case 11:
            if (*self->ptr != 3 && *self->ptr != 0) {
                self->state = 13;
            }
            return;
        case 13:
            if (*self->ptr == 2) {
                self->state = 14;
            }
            return;
        case 14:
            if (*self->ptr != 1 && *self->ptr != 2) {
                self->v27(0);
                self->state = 10;
            } else {
                self->v27(1);
            }
            return;
        default:
            break;
    }
}
