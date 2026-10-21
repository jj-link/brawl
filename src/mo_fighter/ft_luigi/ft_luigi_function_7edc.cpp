#pragma force_active on
struct Pair {
    int key;
    int value;
};

class Base {
public:
    virtual unsigned int f2();
    virtual int* f3(int);
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual int f15();
};

extern "C" Base* fn_99_7EA0(void);

extern "C" void fn_99_7EDC(int unused0, int unused1, Pair* pairs) {
    Base* obj = fn_99_7EA0();
    if (obj->f2() != 1 && pairs != 0) {
        for (int i = 0;; i++) {
            if (i >= obj->f15()) {
                break;
            }
            Pair* entry = pairs + i;
            int key = entry->key;
            if (key < 0) {
                break;
            }
            int value = entry->value;
            *obj->f3(key) = value;
        }
    }
}
