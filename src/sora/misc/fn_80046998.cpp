#pragma force_active on
extern "C" bool fn_80046998(void* p) {
    return *reinterpret_cast<unsigned int*>(static_cast<char*>(p) + 0x3C) != 0;
}
