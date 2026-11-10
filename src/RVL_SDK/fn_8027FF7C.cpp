#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1(void* p);
};

extern Object_vptr_0* lbl_805A0EB8;

struct SomeStruct {
    void* m_00;
    char pad[0xC];
    s8 m_10;
};

extern "C" void fn_8027FF7C(SomeStruct* self) {
    void* ptr = self->m_00;
    int valid = 0;
    if (ptr != 0) {
        if (self->m_10 != 0) {
            valid = 1;
        }
    }
    if (valid == 0) {
        return;
    }
    lbl_805A0EB8->slot1(ptr);
}
