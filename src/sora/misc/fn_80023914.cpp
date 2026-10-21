#pragma force_active on
extern "C" int fn_80023914(void* object)
{
    unsigned char count = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(object) + 0x4);
    char* p = reinterpret_cast<char*>(object);
    int index = 0;

    for (int i = 0; i < count; i++) {
        if (*reinterpret_cast<int*>(p + 0xC) == 3) {
            return *reinterpret_cast<int*>(reinterpret_cast<char*>(object) + index * 8 + 0x10);
        }
        p += 8;
        index++;
    }

    return *reinterpret_cast<int*>(reinterpret_cast<char*>(object) + 0x10);
}
