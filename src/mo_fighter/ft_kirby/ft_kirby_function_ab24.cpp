#pragma force_active on
extern "C" void *fn_96_A390(void *r3, int r4);

extern "C" void *fn_96_AB24(void *r3, int r4)
{
    switch (r4) {
    case 0:
        return r3;
    case 1:
        return (char *)r3 + 0x70c;
    case 2:
        return fn_96_A390(r3, r4);
    default:
        return fn_96_A390(r3, r4);
    }
}
