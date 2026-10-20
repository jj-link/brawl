#pragma force_active on
struct Target {
    unsigned char pad0[0x30];
    unsigned int value;
    unsigned char pad34[0x48E - 0x34];
    unsigned char flag : 1;
    unsigned char otherFlags : 7;
};

struct Context {
    Target* target;
    unsigned char pad4[6];
    unsigned char state;
};

extern "C" void fn_27_1119E0(Context* self, unsigned int value)
{
    if (self->state == 1) {
        self->target->value = value;
    }
    self->target->flag = 0;
}
