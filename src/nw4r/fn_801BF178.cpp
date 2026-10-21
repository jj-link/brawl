#pragma force_active on
extern const float lbl_805A34E8;

extern "C" void fn_801BF178(void* object, float scale)
{
    *reinterpret_cast<unsigned int*>(static_cast<char*>(object) + 0x0) = 0;
    *reinterpret_cast<float*>(static_cast<char*>(object) + 0x4) = lbl_805A34E8 * scale;
}
