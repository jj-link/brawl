#pragma force_active on
struct T
{
    unsigned int pad[98];
    unsigned int value;
    float amount;
};

extern "C" void fn_89_198C(T* self, unsigned int* outInt, float* outFloat)
{
    *outInt = self->value;
    *outFloat = self->amount;
}
