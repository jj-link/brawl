#pragma force_active on
extern "C" int fn_10_84BC(void* object)
{
    int count = *reinterpret_cast<int*>(
        reinterpret_cast<char*>(object) + 0x648);

    for (int index = 0; index < count; ++index) {
        void* entry = *reinterpret_cast<void**>(
            reinterpret_cast<char*>(object) + 0x44);
        void* state = *reinterpret_cast<void**>(
            reinterpret_cast<char*>(entry) + 0x1A8);

        if (*reinterpret_cast<int*>(
                reinterpret_cast<char*>(state) + 0xA4) == 4) {
            return index;
        }

        object = reinterpret_cast<char*>(object) + 4;
    }

    return -1;
}
