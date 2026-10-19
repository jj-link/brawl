#pragma force_active on
struct St {
    char pad[0x5b0];
    unsigned int a;
    char pad2[4];
    unsigned int b;
};

extern "C" void fn_62_551C(St *self, unsigned int a, unsigned int b) {
    self->a = a;
    self->b = b;
}
