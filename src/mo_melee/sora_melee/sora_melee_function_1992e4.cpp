#pragma force_active on
extern "C" void fn_27_1992E4(unsigned int *p, unsigned int value)
{
    struct Word {
        unsigned int pad : 12;
        unsigned int field : 6;
        unsigned int rest : 14;
    };

    ((Word *)(p + 2))->field = value;
}
