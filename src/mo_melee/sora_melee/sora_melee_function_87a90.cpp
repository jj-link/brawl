#pragma force_active on

class Item {};
typedef void (Item::*Callback)();

extern "C" Callback lbl_27_data_13264;
extern "C" Callback* fn_803F0E60(void*, const Callback*, Callback*);

class List {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Item** get(int);
    virtual void slot3();
    virtual int size();
};

struct Owner {
    char pad[0x14];
    List* list;
};

extern "C" void fn_27_87A90(Owner* self) {
    Callback member;
    Callback adjusted;
    member = *fn_803F0E60((void*)6, &lbl_27_data_13264, &adjusted);

    int end = self->list->size() - 1;
    Callback callback = member;

    if (self->list->size() <= end)
        end = self->list->size() - 1;

    for (int i = 0; i <= end; ++i) {
        Item* item = *self->list->get(i);
        if (item)
            (item->*callback)();
    }
}
