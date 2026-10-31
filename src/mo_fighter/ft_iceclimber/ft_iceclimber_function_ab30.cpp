#pragma force_active on
extern "C" void fn_27_132174(void* obj, unsigned int mode);

extern "C" void fn_105_AB30(void* obj, unsigned int mode)
{
    if (static_cast<unsigned char*>(obj)[0x1FE4C] == 0)
        fn_27_132174(obj, mode);
}
