#pragma force_active on
struct Pair {
    int key;
    int value;
};

class ftWorkObj {
public:
    virtual unsigned int slot2();
    virtual int* slot3(int key);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual int slot15();
};

extern "C" ftWorkObj* fn_97_A014(void* arg);

extern "C" void fn_97_A050(void* arg, void* unused, Pair* pairs) {
    ftWorkObj* obj = fn_97_A014(arg);
    if (obj->slot2() != 1 && pairs != 0) {
        for (int i = 0; ; i++) {
            if (i >= obj->slot15()) {
                break;
            }
            Pair* p = &pairs[i];
            int key = p->key;
            if (key < 0) {
                break;
            }
            int value = p->value;
            *obj->slot3(key) = value;
        }
    }
}
