#pragma force_active on
struct Entry {
    int key;
    int value;
};

class Base {
public:
    virtual unsigned int v0();
    virtual int* v1(int key);
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
    virtual int v13();
};

extern "C" Base* fn_113_9F1C(Base* self);

extern "C" void fn_113_9F58(Base* self, int unused, Entry* entries) {
    Base* obj = fn_113_9F1C(self);
    if (obj->v0() == 1) return;
    if (entries == 0) return;

    for (int i = 0;;) {
        if (i >= obj->v13()) return;
        Entry* e = entries + i;
        int key = e->key;
        if (key < 0) return;
        int value = e->value;
        *obj->v1(key) = value;
        i++;
    }
}
