#pragma force_active on
extern "C" bool fn_800469AC(void* p) {
    return *reinterpret_cast<unsigned int*>(static_cast<char*>(p) + 0x48) != 0;
}
