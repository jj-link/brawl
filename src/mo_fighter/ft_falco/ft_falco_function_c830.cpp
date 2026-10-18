#pragma force_active on
extern "C" void* fn_108_C830(void* object, int index)
{
    if (index == 4) {
        return static_cast<char*>(object) + 0x85fc;
    }
    if (index == 3) {
        return static_cast<char*>(object) + 0x6484;
    }
    if (index == 2) {
        return static_cast<char*>(object) + 0x430c;
    }
    if (index == 1) {
        return static_cast<char*>(object) + 0x2194;
    }
    if (index == 0) {
        return static_cast<char*>(object) + 0x1c;
    }
    return 0;
}
