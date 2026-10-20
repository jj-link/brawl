#pragma force_active on
struct Source {
    unsigned char padding[0x14];
    unsigned char value;
};

struct Destination {
    Source* source;
    unsigned char value;
};

extern "C" void fn_41_2A4E0(Destination* self) {
    self->value = self->source->value;
}
