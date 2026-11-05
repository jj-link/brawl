#pragma force_active on

struct Result {
    int* data;
    unsigned char flag;
};

class Owner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void set(bool);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual int accept(signed char);
};

class Actor {
public:
    virtual void h0();
    virtual signed char category();
    virtual signed char state();
    virtual int v3();
    virtual void v4();
    virtual void v5();
    virtual bool getResult(Result*, int);
};

extern "C" int fn_27_5B050(Owner* self, Actor* arg) {
    if (self->accept(arg->category()) == 0) {
        return 0;
    }
    if (arg->state() <= -1 || arg->state() >= 4) {
        return 0;
    }
    switch (arg->state()) {
    case 0:
    case 1:
        return 1;
    case 2: {
        Result local;
        local.data = 0;
        local.flag = 0;
        if (arg->v3() < 1) {
            return 1;
        }
        arg->getResult(&local, 0);
        int value;
        if (local.flag == 1) {
            value = -1;
        } else {
            value = *local.data;
        }
        if (value != 3) {
            return 1;
        }
        bool flag;
        if (local.flag == 1) {
            flag = 0;
        } else {
            flag = (local.data[1] != 0);
        }
        self->set(flag);
        return 1;
    }
    default:
        return 0;
    }
}
