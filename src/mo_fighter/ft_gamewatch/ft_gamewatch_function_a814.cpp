#pragma force_active on
class Obj {
public:
    virtual int f0();
    virtual int* f1(int key);
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
    virtual int f13();
};

struct Entry {
    int key;
    int value;
};

extern "C" Obj* fn_107_A7D8(void* p);

extern "C" void fn_107_A814(void* p, void* unused, Entry* table) {
    Obj* o = fn_107_A7D8(p);
    if ((unsigned int)o->f0() != 1 && table != 0) {
        int i = 0;
        for (;;) {
            if (i >= o->f13()) break;
            Entry* e = &table[i];
            int key = e->key;
            if (key < 0) break;
            int value = e->value;
            *o->f1(key) = value;
            i++;
        }
    }
}
