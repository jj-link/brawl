#include <types.h>
#pragma force_active on

class VObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int, int);
};

struct sndSystem {
    unsigned char pad[0x6E0];
    VObj* field_6E0;
    unsigned char pad_6E4[0x3C];
    unsigned char field_720;
    unsigned char field_721;
    unsigned char pad_722[2];
    int field_724;
};

extern "C" void fn_80076860(sndSystem*, int);

extern "C" void specialPause__9sndSystemFv(sndSystem* self) {
    if (self->field_720 == 0) {
        fn_80076860(self, 0);
        self->field_721 = 1;
    }
    if (self->field_724 != 1) {
        VObj* p = self->field_6E0;
        if (p != 0) {
            p->v5(1, 0);
        }
    }
}