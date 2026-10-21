#pragma force_active on

struct Actor;
struct Data;

struct Service {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual unsigned int test(Actor*, Data*);
};

struct Modules {
    char padding[0x70];
    Service* service;
};

struct Actor {
    char padding[0xD8];
    Modules* modules;
};

struct Data {
    char padding[0x9C];
    unsigned char enabled;
};

struct Object {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void fallback(Actor*, Data*, int, int);
    virtual void unused22();
    virtual void unused23();
    virtual void success(Actor*, Data*, int);
};

extern "C" int fn_27_61EE8(Object*, Actor*, Data*, int, unsigned char*);

extern "C" int fn_27_620B8(Object* self, Actor* actor, Data* data, int arg3) {
    unsigned char flag = 0;
    if (fn_27_61EE8(self, actor, data, arg3, &flag) == 0) {
        if (flag == 1 && data->enabled == 0) {
            return 0;
        }
        if (actor->modules->service->test(actor, data) == 1U) {
            self->success(actor, data, arg3);
            return 1;
        }
        self->fallback(actor, data, arg3, -1);
    }
    return 1;
}
