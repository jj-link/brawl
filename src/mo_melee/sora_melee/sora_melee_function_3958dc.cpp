#pragma force_active on
struct S
{
    unsigned int pad[2];
    unsigned int field;
};

extern "C" void fn_27_3958DC(S* self, unsigned int value)
{
    self->field = __rlwimi(self->field, value, 20, 8, 11);
}
