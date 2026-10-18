#pragma force_active on
extern const float lbl_101_rodata_A0;

extern "C" void fn_101_15E60(void* self)
{
    float v = lbl_101_rodata_A0;
    *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(self) + 0xC) = v;
    *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(self) + 0x8) = v;
}
