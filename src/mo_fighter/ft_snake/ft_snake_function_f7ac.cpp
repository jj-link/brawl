#pragma force_active on
extern "C" float fn_122_F7AC(const float* object, unsigned int index)
{
    return *reinterpret_cast<const float*>(*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(object) + 0x14) + index * 4);
}
