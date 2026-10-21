#pragma force_active on
struct TableEntry {
    int key;
    unsigned int value;
};

class ftIceObj {
public:
    virtual unsigned int vfn0();
    virtual unsigned int* vfn1(int key);
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual int vfn13();
};

extern "C" ftIceObj* fn_105_A0A4(void* a);

extern "C" void fn_105_A0E0(void* a, void* b, TableEntry* table) {
    ftIceObj* obj = fn_105_A0A4(a);
    if (obj->vfn0() == 1) return;
    if (table == 0) return;

    int i = 0;
    while (true) {
        if (i >= obj->vfn13()) break;
        TableEntry* e = &table[i];
        int key = e->key;
        if (key < 0) break;
        unsigned int value = e->value;
        unsigned int* p = obj->vfn1(key);
        *p = value;
        i++;
    }
}
