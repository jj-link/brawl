#pragma force_active on
struct S
{
    int _0;
    int _4;
    int _8;
};

extern "C" unsigned int fn_70_92E0(const S *s)
{
    return (s->_8 >> 19) & 1;
}
