#pragma force_active on
extern "C" void* fn_8004E688(void* arg) {
    char* p = *reinterpret_cast<char**>((char*)arg + 0x24);
    return p + 0x2A0;
}
