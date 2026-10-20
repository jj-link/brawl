#pragma force_active on
extern "C" void fn_27_3689A4(void* object)
{
    float value = *reinterpret_cast<float*>(static_cast<char*>(object) + 0x10);
    *reinterpret_cast<unsigned int*>(static_cast<char*>(object) + 0x08) = 0;
    *reinterpret_cast<float*>(static_cast<char*>(object) + 0x0C) = value;
}
