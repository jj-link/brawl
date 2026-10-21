#pragma force_active on
struct State {
    unsigned int pad[2];
    unsigned int : 8;
    unsigned int field : 4;
    unsigned int : 20;
};

extern "C" void fn_67_52C8(State* self, unsigned int value)
{
    self->field = value;
}
