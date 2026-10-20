#pragma force_active on
struct FloatBlock {
    char pad[0x174];
    float a;
    float b;
    float c;
};

extern "C" void fn_66_180C(FloatBlock* self, float x, float y, float z) {
    self->a = x;
    self->b = y;
    self->c = z;
}
