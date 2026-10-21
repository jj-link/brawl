#pragma force_active on
extern const float lbl_805A3530;

extern "C" void fn_801C0AD4(void* object)
{
    *reinterpret_cast<unsigned int*>(static_cast<char*>(object) + 0x10) = 0;
    *reinterpret_cast<float*>(static_cast<char*>(object) + 0x14) = lbl_805A3530;
}
