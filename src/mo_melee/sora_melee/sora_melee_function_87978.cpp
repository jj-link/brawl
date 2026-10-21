#pragma force_active on

class Target {};
typedef void (Target::*Callback)();

extern "C" Callback lbl_27_data_13258;
extern "C" Callback* fn_803F0E60(int, const Callback*, Callback*);

class Container {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Target** get(int);
    virtual void slot2();
    virtual int size();
};

struct Owner {
    char pad[0x14];
    Container* container;
};

extern "C" void fn_27_87978(Owner* self) {
    Callback callback;
    Callback adjusted;
    callback = *fn_803F0E60(6, &lbl_27_data_13258, &adjusted);

    int last = self->container->size() - 1;
    Callback call = callback;

    if (self->container->size() <= last)
        last = self->container->size() - 1;

    for (int i = 0; i <= last; ++i) {
        Target* target = *self->container->get(i);
        if (target)
            (target->*call)();
    }
}
