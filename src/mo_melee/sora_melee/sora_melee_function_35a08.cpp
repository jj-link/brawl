#pragma force_active on

struct Result {
    int* data;
    unsigned char flag;
};

class Actor {
public:
    virtual void h0();
    virtual signed char category();
    virtual signed char state();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool getResult(Result*, int);
};

class Owner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void set(int, int);
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
    virtual int accept(signed char);
};

extern "C" int fn_27_35A08(Owner* self, Actor* actor) {
    if (self->accept(actor->category()) == 0) return 0;

    if (actor->state() <= -1 || actor->state() >= 1) return 0;

    switch (actor->state()) {
    case 0:
        goto process;
    default:
        goto fail;
    }

process:
    {
        Result local;
        local.data = 0;
        local.flag = 0;

        if (actor->getResult(&local, 0) == 0) goto success;

        int value;
        if (local.flag == 1) value = -1;
        else value = *local.data;

        if (value == 0) goto update;

success:
        return 1;

update:
        {
            int arg;
            if (local.flag == 1) arg = 0;
            else arg = local.data[1];

            self->set(arg, 0);
        }
        return 1;
    }

fail:
    return 0;
}
