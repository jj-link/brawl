#pragma force_active on
extern "C" bool fn_90_A4(void* obj) {
    return *reinterpret_cast<int*>(static_cast<char*>(obj) + 0x200) == 4;
}
