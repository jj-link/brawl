#pragma force_active on
struct emIndexedAccesser {
    virtual void v0();
    virtual int* get(int idx);
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
    virtual int count();
};

class emFoo {
public:
    unsigned char unk0[0x264];
    emIndexedAccesser unk264;
};

extern "C" {
void fn_41_2C3D0(emFoo* self) {
    for (int i = 0; i < self->unk264.count(); i++) {
        *self->unk264.get(i) = 0;
    }
}
}
