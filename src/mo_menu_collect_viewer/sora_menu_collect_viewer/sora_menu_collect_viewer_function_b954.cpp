#pragma force_active on
struct DialogBase {
    char padding[0x3C];
};

struct Dialog : DialogBase {
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
    virtual void close();

    char padding1[8];
    int result;
    char padding2[4];
    int state;
};

struct Viewer {
    char padding0[0x128];
    int state;
    char padding1[0x24];
    Dialog* dialog;
};

extern "C" int fn_6_B954(Viewer* self) {
    Dialog* dialog = self->dialog;
    if (dialog->state == 5) {
        int result = dialog->result;
        dialog->close();
        self->dialog = 0;
        return result == 1 ? 12 : 8;
    }
    return self->state;
}
