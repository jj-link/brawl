#pragma force_active on
extern "C" void fn_16_70A0(void*);
extern "C" void fn_16_74B8(void*);
struct Obj { char pad[0xd4]; int state; };
extern "C" void fn_16_6D88(Obj* self) {
    switch (self->state) {
    case 1:
        fn_16_70A0(self);
        break;
    case 2:
        fn_16_74B8(self);
        break;
    }
}