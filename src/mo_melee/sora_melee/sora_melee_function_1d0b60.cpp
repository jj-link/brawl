#pragma force_active on
struct Fn27Owner {
    char pad[8];
    int field8;
};

extern "C" {
void* fn_27_1D0B60(Fn27Owner* self, int idx)
{
    int i = (self->field8 >> 28) + idx;
    if (i >= 4) {
        i -= 4;
    }
    return (char*)self + 12 + i * 12;
}
}
