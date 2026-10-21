#pragma force_active on
struct Entry {
    void* value;
};

struct Array {
    virtual void f0();
    virtual Entry* at(int);
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual int size();
};

struct Owner {
    char pad[0x264];
    Array array;
};

struct Target {
    char pad[0x221A];
    unsigned char flag;
};

extern "C" void fn_41_2C448(Owner* owner, Target* target) {
    int i = 0;
    while (i < owner->array.size()) {
        Entry* e = owner->array.at(i);
        if (e->value == 0) {
            owner->array.at(i)->value = target;
            target->flag = 1;
            return;
        }
        ++i;
    }
}
