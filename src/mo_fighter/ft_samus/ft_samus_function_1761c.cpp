#pragma force_active on

extern "C" void fn_27_12BAF8(void*, int);

class Sub {
public:
    virtual int check();
};

class Obj84 {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Sub* get(int, int, bool);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void set(Sub*);
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual int test(int);
};

class Obj64 {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void set(int, unsigned int);
};

extern "C" void fn_94_1761C(char* self, int arg) {
    fn_27_12BAF8(self, arg);
    Obj84* obj = *(Obj84**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x84);
    if (obj->test(0) == 0) {
        Sub* sub = obj->get(0, 0, false);
        if (sub->check() == 0) {
            obj->set(sub);
        }
    }
    Obj64* o = *(Obj64**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    o->set(-1, 0x10000041);
}
