#include <types.h>
#pragma force_active on

class Elem {
public:
    virtual void v0() = 0;
    virtual Elem* iterate(int idx) = 0;
    virtual void v2() = 0;
    virtual int size() = 0;
};

struct ThisClass {
    char pad[0x34];
    int field_34;
    char pad2[0x20];
    Elem* elem;
};

extern "C" void fn_27_41C28(Elem* p);
extern "C" void fn_27_35E54(void* p);

extern "C" void fn_27_43480(ThisClass* self) {
    for (int i = 0; i < self->elem->size(); i++) {
        fn_27_41C28(self->elem->iterate(i));
    }
    self->field_34 = 0;
    fn_27_35E54((char*)self + 0x38);
}
