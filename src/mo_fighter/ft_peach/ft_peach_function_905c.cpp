#pragma force_active on
struct Obj {
    virtual unsigned int f0() = 0;
    virtual int* f1(int key) = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual int f13() = 0;
};

struct Entry {
    int key;
    int value;
};

extern "C" Obj* fn_103_9020(void* p);

extern "C" void fn_103_905C(void* p, int unused, Entry* table) {
    Obj* obj = fn_103_9020(p);
    if (obj->f0() != 1 && table != 0) {
        int i = 0;
        while (true) {
            if (i >= obj->f13()) {
                break;
            }
            Entry* e = &table[i];
            int key = e->key;
            if (key < 0) {
                break;
            }
            int value = e->value;
            int* dst = obj->f1(key);
            *dst = value;
            i++;
        }
    }
}
