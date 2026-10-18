#pragma force_active on
extern "C" void fn_101_FF08(void* object)
{
    *reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(object) + 0x31) = 0;
}
