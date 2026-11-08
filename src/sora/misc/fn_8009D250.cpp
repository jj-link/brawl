#pragma force_active on
extern "C" void fn_8009FCF4(char*, float);
struct Obj { char pad0[0x40]; int kind; char pad44[0x14]; char* ptr; char pad5c[0x12c]; int count; };
extern "C" void fn_8009D250(Obj* self) {
    if (self->count == 0 && self->kind == 13 && self->ptr != 0) {
        fn_8009FCF4(self->ptr, 10.0f);
    }
    self->count = self->count + 1;
}
