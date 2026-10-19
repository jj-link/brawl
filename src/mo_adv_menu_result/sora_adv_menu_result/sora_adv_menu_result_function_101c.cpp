#pragma force_active on
struct Result {
    unsigned char pad0[0xFC];
    unsigned int value;
    unsigned char pad100[0x494];
    unsigned int saved;
};

extern "C" void fn_34_1080(Result*);

extern "C" void fn_34_101C(Result* self) {
    fn_34_1080(self);
    self->saved = self->value;
}
