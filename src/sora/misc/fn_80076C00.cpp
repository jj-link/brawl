#include <types.h>
#pragma force_active on

class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4(int, int);
};

struct sndSystem {
    unsigned char pad[0x6E0];
    Class_8042B6D0* field_6E0;
    unsigned char pad_6E4[0x3D];
    unsigned char field_721;
    unsigned char pad_722[2];
    int field_724;
};

extern "C" void fn_80076A6C(sndSystem*, int);

extern "C" void specialResume__9sndSystemFv(sndSystem* self) {
    if (self->field_724 != 1) {
        Class_8042B6D0* p = self->field_6E0;
        if (p != 0) {
            p->fn_801AB1C4(0, 0);
        }
    }
    if (self->field_721 != 0) {
        fn_80076A6C(self, 0);
        self->field_721 = 0;
    }
}
