#pragma force_active on
struct Container {
    char filler[0x14];
    float* data;
};

extern "C" void fn_103_A1FC(Container* c, int index, float value)
{
    c->data[index] = value;
}
