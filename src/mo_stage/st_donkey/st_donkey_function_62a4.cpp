#pragma force_active on
extern "C" int fn_50_62A4(const void *arg)
{
    const unsigned int value =
        *reinterpret_cast<const unsigned int *>(
            static_cast<const char *>(arg) + 8);
    return static_cast<int>((value << 2) & 0xE0000000u) >> 30;
}
