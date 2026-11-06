#include <types.h>
#pragma force_active on
class Sub { public: virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); };
class Object_vptr_0 {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(int,int,int); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(int);
    char pad04[0x30]; Sub sub; char pad38[0x14]; float f4c; int f50, f54, f58, f5c, f60, f64, f68, f6c;
};
extern const float lbl_27_rodata_D78;
extern "C" void fn_27_ACF58(Object_vptr_0*);
extern "C" void fn_27_ACDAC(Object_vptr_0* self) {
    self->slot2(0, 0, 0);
    fn_27_ACF58(self);
    self->f54 = 0;
    self->f4c = lbl_27_rodata_D78;
    self->f50 = 0;
    self->f5c = 0;
    self->f58 = 0;
    self->f64 = 0;
    self->f60 = 0;
    self->f68 = 0;
    self->f6c = 0xffff;
    self->slot6(0);
    self->sub.slot8();
}