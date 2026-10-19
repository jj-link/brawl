#pragma force_active on
struct LucasFlags {
    unsigned char padding[0xA4];
    unsigned char reserved : 1;
    unsigned char enabled : 1;
    unsigned char rest : 6;
};

extern "C" void fn_114_157FC(LucasFlags* self, unsigned int enabled) {
    self->enabled = enabled;
}
