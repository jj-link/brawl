#pragma force_active on
struct Kart {
    unsigned int padding[2];
    unsigned int reserved : 2;
    unsigned int value : 2;
    unsigned int remaining : 28;
};

extern "C" void fn_49_6C3C(Kart* self, unsigned int value)
{
    self->value = value;
}
