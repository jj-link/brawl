#pragma force_active on

class Target {};
typedef void (Target::*Member)();

extern "C" Member lbl_27_data_13270;
extern "C" Member* fn_803F0E60(void*, const Member*, Member*);

class Container {
public:
    virtual ~Container();
    virtual void slot1();
    virtual Target** get(int);
    virtual void slot2();
    virtual int size();
};

struct Owner {
    char pad[0x14];
    Container* entries;
};

extern "C" void fn_27_87BAC(Owner* self) {
    Member member;
    Member adjusted;
    member = *fn_803F0E60((void*)5, &lbl_27_data_13270, &adjusted);

    int last = self->entries->size() - 1;
    Member call = member;

    if (self->entries->size() <= last)
        last = self->entries->size() - 1;

    for (int i = 0; i <= last; ++i) {
        Target* object = *self->entries->get(i);
        if (object)
            (object->*call)();
    }
}
