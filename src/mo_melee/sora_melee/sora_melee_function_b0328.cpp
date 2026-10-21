#pragma force_active on
struct Data {
    unsigned int a;
    unsigned int b;
    short c;
    short d;
};

extern "C" void fn_27_B0328(Data* self, const unsigned int* a,
                           unsigned int b, const short* c, short d)
{
    self->a = *a;
    self->b = b;
    self->c = *c;
    self->d = d;
}
