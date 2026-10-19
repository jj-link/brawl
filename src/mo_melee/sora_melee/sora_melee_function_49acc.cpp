#include <types.h>
#pragma force_active on

struct SoHolder;
struct SoObj;

struct HolderProvider {
    virtual void slot0();
    virtual SoHolder* getHolder();
};

struct Object {
    u8 pad0[0x20];
    SoObj* object;
    u8 pad24[0x24];
    HolderProvider* provider;
};

extern "C" void fn_27_4702C(SoHolder* holder, SoObj* obj);

extern "C" void fn_27_49ACC(Object* self) {
    fn_27_4702C(self->provider->getHolder(), self->object);
}
