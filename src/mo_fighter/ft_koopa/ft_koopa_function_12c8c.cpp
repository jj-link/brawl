#pragma force_active on
struct Entry {
    int key;
    int value;
};

class Obj {
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

extern "C" Obj* fn_102_12C50(void* self);

extern "C" void fn_102_12C8C(void* self, int unused, Entry* arr) {
    Obj* o = fn_102_12C50(self);
    if (o->v0() != 1 && arr != 0) {
        int i = 0;
        while (true) {
            if (i >= o->v13()) {
                break;
            }
            Entry* e = &arr[i];
            int key = e->key;
            if (key < 0) {
                break;
            }
            int value = e->value;
            int* p = o->v1(key);
            *p = value;
            i++;
        }
    }
}
