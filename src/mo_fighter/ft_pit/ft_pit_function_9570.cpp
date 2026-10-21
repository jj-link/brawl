#pragma force_active on
struct Entry {
    int key;
    int value;
};

class fnObj {
public:
    virtual unsigned int vf0();
    virtual int* vf1(int key);
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual int vf13();
};

extern "C" fnObj* fn_112_9534(fnObj*);

extern "C" void fn_112_9570(fnObj* self, int, Entry* table) {
    fnObj* obj = fn_112_9534(self);
    if (obj->vf0() != 1 && table != 0) {
        int i = 0;
        for (;;) {
            if (i >= obj->vf13()) {
                break;
            }
            Entry* e = &table[i];
            int key = e->key;
            if (key < 0) {
                break;
            }
            int value = e->value;
            *obj->vf1(key) = value;
            i++;
        }
    }
}
