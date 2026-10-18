#pragma force_active on
extern "C" int fn_6_9640(void* object) {
    unsigned char* self = static_cast<unsigned char*>(object);

    if (*reinterpret_cast<int*>(self + 0x784) == 2) {
        *reinterpret_cast<int*>(self + 0x77c) = 3;
        *reinterpret_cast<int*>(self + 0x780) = 0;
        self[0x774] = 1;
        return 0x0d;
    }

    unsigned char* state = *reinterpret_cast<unsigned char**>(self + 0x730);
    if (state[0x8c] == 0)
        return *reinterpret_cast<int*>(self + 0x124);

    if (*reinterpret_cast<int*>(state + 0x90) != 0)
        return *reinterpret_cast<int*>(self + 0x124);

    return 1;
}
