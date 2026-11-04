#pragma force_active on
struct Entry {
    int value;
    signed int key : 16;
    unsigned int other : 16;
};
class Class_54750 {
public:
    virtual void fn_27_25EF44();
    virtual Entry* fn_27_21CB30(int);
    virtual void fn_27_25EBF8();
    virtual int fn_27_21CD40();
    virtual void fn_27_1F00C();
    virtual void fn_27_25EA2C();
    virtual void fn_27_25ECCC();
    virtual void fn_27_25ED78();
    virtual void fn_27_25EA94();
    virtual void fn_27_25EC74();
    virtual void fn_27_25ED08();
    virtual void fn_27_25EDCC(int, Entry*);
    virtual void fn_27_25EE24();
    virtual void fn_27_21CD50();
    virtual unsigned int fn_27_25EE5C();
};
struct Object {
    void* vtable;
    Class_54750* list;
    inline int find(int key) {
        if (key < 0) return -1;
        int n = list->fn_27_21CD40();
        for (int i = 0; i < n; i++) {
            if (list->fn_27_21CB30(i)->key > key) return i;
        }
        return n;
    }
};
extern "C" int fn_27_21DA4(Object* self, int key, int value, int other) {
    if (self->list->fn_27_25EE5C() == 1U) return 0;
    int i = self->find(key);
    if (i < 0) return 0;
    Entry entry;
    entry.value = value;
    entry.key = key;
    entry.other = other;
    self->list->fn_27_25EDCC(i, &entry);
    return 1;
}