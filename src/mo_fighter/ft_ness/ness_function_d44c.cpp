#pragma force_active on
struct Owner {
    int a;
    int b;
    int c;
    int d;
    int e;
    float* values;
};

extern "C" float fn_101_D44C(Owner* owner, int index)
{
    float* base = owner->values;
    return base[index];
}
