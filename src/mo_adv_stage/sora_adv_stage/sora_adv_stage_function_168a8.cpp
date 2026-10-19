#pragma force_active on
extern "C" void fn_40_15CBC();

extern "C" void fn_40_168A8(void* self)
{
    fn_40_15CBC();
    *((unsigned char*)self + 6) = 1;
}
