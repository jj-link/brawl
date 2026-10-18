#pragma force_active on
extern "C" void fn_27_2EF48(void* arg0, unsigned char value)
{
    void* object = *reinterpret_cast<void**>(static_cast<char*>(arg0) + 4);
    *reinterpret_cast<unsigned char*>(static_cast<char*>(object) + 0x6E) = value;
}
