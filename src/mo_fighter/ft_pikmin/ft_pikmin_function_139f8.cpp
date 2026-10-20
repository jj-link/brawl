#pragma force_active on
struct S {
    char pad[8];
    unsigned int x : 5;
    unsigned int bits : 27;
};

extern "C" void fn_113_139F8(S* s, int value)
{
    s->x = value;
}
