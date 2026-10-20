#pragma force_active on
struct CopyData
{
    unsigned char a;
    short b;
    short c;
};

extern "C" void fn_27_7756C(CopyData* dst, const CopyData* src)
{
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
}
