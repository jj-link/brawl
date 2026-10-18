#pragma force_active on
extern "C" void fn_40_15D3C();

extern "C" void fn_40_168F0(void* object)
{
    static_cast<unsigned char*>(object)[6] = 0;
    fn_40_15D3C();
}
