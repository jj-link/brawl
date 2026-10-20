#pragma force_active on
struct S
{
    int pad[2];
    unsigned int x : 5;
    signed int y : 6;
};

extern "C" int fn_76_3388(S* s)
{
    return ((int)(s->y << 26)) >> 27;
}
