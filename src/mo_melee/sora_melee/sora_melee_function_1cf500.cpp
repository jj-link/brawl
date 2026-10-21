#pragma force_active on
struct Entry {
    unsigned int field0;
    unsigned int field4;
    short field8;
    short fieldA;
};

extern "C" void fn_27_1CF500(
    Entry* self,
    const unsigned int* a,
    unsigned int b,
    const short* c,
    short d)
{
    self->field0 = *a;
    self->field4 = b;
    self->field8 = *c;
    self->fieldA = d;
}
