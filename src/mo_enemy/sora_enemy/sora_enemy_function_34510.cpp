#pragma force_active on
struct Item {
    void* p;
};

class Member {
public:
    virtual void v0();
    virtual Item getItem(int index);
    virtual void v2();
    virtual int getCount();
};

class Visitor {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void visit(Item& item);
};

class Owner {
public:
    char pad[0x10];
    Member mem;
};

extern "C" {
void fn_41_34510(Owner* self, Visitor* v) {
    int n = self->mem.getCount();
    for (int i = 0; i < n; i++) {
        Item item = self->mem.getItem(i);
        v->visit(item);
    }
}
}
