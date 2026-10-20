#pragma force_active on
struct FdfeStruct {
    unsigned int a;
    unsigned int b;
    short c;
    short d;
};

extern "C" void fn_27_FDFE4(FdfeStruct* out, const unsigned int* src, unsigned int val, const short* sp, short dv)
{
    out->a = *src;
    out->b = val;
    out->c = *sp;
    out->d = dv;
}
