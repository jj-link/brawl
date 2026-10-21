#pragma force_active on

class Inner {
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
    virtual void invoke(void*);
};

struct Base {
    char padding0[0x654];
    Inner* inner;
    char padding658[0x10];

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
    virtual void invoke();
};

struct Self : Base {
    int field66c;
    int state;
    char padding674[8];
    void* target;
    char padding680[0xC];
    void* first;
    void* second;
};

extern "C" {
extern const unsigned char lbl_2_rodata_EC4[];
extern char lbl_2_data_3358[];

void fn_800B330C(void*, void*, int);

void fn_2_29324(Self* self, int arg) {
    int state;

    switch (arg) {
    case 0:
        state = 3;
        break;
    case 1:
        state = 5;
        break;
    case 2:
        state = 3;
        break;
    }

    if (state != self->state) {
        self->state = state;
        if (state == 0) {
            self->inner->invoke(self->first);
            self->inner->invoke(self->second);
            return;
        }
        if (state == 1) {
            self->invoke();
        }
        fn_800B330C(
            self->target,
            lbl_2_data_3358 + lbl_2_rodata_EC4[state] * 0x14,
            0
        );
    }
}
}
