#pragma force_active on
struct Entry {
    void* unk0;
    int unk4;
};

struct Array {
    virtual void v0();
    virtual Entry* at(int);
    virtual void v4();
    virtual void v5();
    virtual int v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual int size();
};

struct Owner {
    char pad[0x28];
    Array array;
};

extern "C" void* fn_41_2C31C(Owner* owner, int arg1) {
    int i;
    if (owner->array.v6() != 0) {
        return 0;
    }
    for (i = 0; i < owner->array.size(); i++) {
        Entry* e = owner->array.at(i);
        if (e != 0 && e->unk4 == arg1) {
            return e->unk0;
        }
    }
    return 0;
}
