#pragma force_active on

class Object_vptr_0;

struct Item {
    Item* next;
    int pad;
    Object_vptr_0* target;
    unsigned short id;
    unsigned char flag;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(unsigned short, void*);
};

class Class_80465980 {
public:
    virtual void fn_801890EC();
    virtual void fn_80189C9C();
    virtual void fn_8018AB3C();
    virtual void fn_8018AB58();
    virtual void fn_8018ABD8();
    virtual void fn_8018ABEC();
    char pad[4];
    Item* head;
};

extern "C" void fn_8018ABEC(Class_80465980* self) {
    Item* it = self->head;
    Item* end = (Item*)&self->head;
    while (it != end) {
        if (it->flag == 0)
            it->target->slot5(it->id, self);
        it = it->next;
    }
}
