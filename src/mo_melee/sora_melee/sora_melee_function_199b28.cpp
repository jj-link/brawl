#pragma force_active on
extern "C" unsigned int fn_27_199B28(const unsigned int *p)
{
    struct X { unsigned a : 15; unsigned f : 1; };
    return (reinterpret_cast<const X *>(p + 2))->f;
}
