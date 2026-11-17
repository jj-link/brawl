#pragma force_active on
#pragma cplusplus on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(void* a, void* b);
};

struct Table {
    char pad[0xB0];
    void* items[1];
};

extern Table* lbl_805A0EC8;

extern "C" void fn_8027E338(Object_vptr_0* self, void* arg, int index) {
    self->slot5(arg, lbl_805A0EC8->items[index]);
}
