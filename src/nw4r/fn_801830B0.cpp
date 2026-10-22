#pragma force_active on
struct Listener {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void notify(unsigned short, void*);
};
struct Item { Item* next; int pad; Listener* l; unsigned short id; unsigned char flag; };
struct Child {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void act();
};
struct Obj {
    char pad[0x20];
    Item* head;
    int pad2;
    Child* child;
    char pad3[0x8B];
    unsigned char bits;
};
extern "C" void fn_801830B0(Obj* o, unsigned int a) {
    Item* it = o->head;
    Item* end = (Item*)&o->head;
    for (; it != end; it = it->next) {
        if (it->flag == 0) it->l->notify(it->id, o);
    }
    if ((o->bits & 1) || !(a & 1)) {
        if (o->child) o->child->act();
    }
}
