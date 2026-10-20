#pragma force_active on
struct S
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int field;
};

extern "C" void fn_27_1A11A8(S* self, unsigned int value)
{
    self->field = __rlwimi(self->field, value, 22, 5, 9);
}
