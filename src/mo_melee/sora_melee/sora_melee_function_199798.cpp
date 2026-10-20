#pragma force_active on
struct S
{
    unsigned int pad[2];
    unsigned int field : 4;
};

extern "C" void fn_27_199798(S* self, unsigned int value)
{
    self->field = value;
}
