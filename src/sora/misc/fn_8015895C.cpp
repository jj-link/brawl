#pragma force_active on
struct Params {
    char pad[0x46];
    signed char increment;
    unsigned char threshold;
};
struct Object {
    char pad[0x10];
    int total;
    unsigned int ids[4];
    unsigned int values[4];
};
extern "C" Params* fn_8014FE34(Object*);
extern "C" void fn_8015895C(Object* self) {
    Params* params = fn_8014FE34(self);
    for (int i = 0; i < 4; ++i) {
        if (self->ids[i] != 0xFFFFFFFF && self->values[i] >= params->threshold) {
            self->total += params->increment;
        }
    }
}
