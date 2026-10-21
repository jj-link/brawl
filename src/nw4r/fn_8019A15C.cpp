extern float lbl_805A32A8;

class Item {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual float vf6();
};

struct Ctx {
    unsigned char pad0[0x18];
    int count;
    Item** items;

    Item* get(int i) const {
        return items[i];
    }
};

#pragma force_active on
extern "C" float fn_8019A15C(Ctx* self) {
    for (int i = 0; i < self->count; i++) {
        if (self->get(i) != 0) {
            return self->get(i)->vf6();
        }
    }
    return lbl_805A32A8;
}
