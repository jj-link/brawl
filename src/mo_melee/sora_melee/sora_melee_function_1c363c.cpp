#pragma force_active on
struct S
{
    unsigned char pad[0x18];
    int state;
};

extern "C" void *fn_27_1C363C(S *p, int index)
{
    int value = p->state >> 28;
    int sum = value + index;
    if (sum >= 4)
        sum = sum - 4;
    return (char *)p + sum * 12 + 0x1C;
}
