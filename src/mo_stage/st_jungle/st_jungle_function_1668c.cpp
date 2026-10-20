#pragma force_active on
extern "C" float fn_51_1668C(const void* object, unsigned int index)
{
    const float* values = *reinterpret_cast<const float* const*>(
        reinterpret_cast<const char*>(object) + 0x520);
    return values[index];
}
