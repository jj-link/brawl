#pragma force_active on
class Item {
public:
    virtual ~Item();
    virtual void unused();
    virtual int get();
};

class Array {
public:
    virtual ~Array();
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual int insert(Item**, int);
};

struct Owner {
    char unused[12];
    Array* array;
};

extern "C" short fn_27_8ED98(Owner* self, Item* item) {
    short index = (short)item->get();
    return (short)self->array->insert(&item, index);
}
