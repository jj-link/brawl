#pragma force_active on
extern "C" int fn_61_A6AC(int *p);

int fn_61_A6AC(int *p)
{
    unsigned int x = (unsigned int)p[2];
    return ((int)((x << 4) & 0xE0000000u)) >> 30;
}
