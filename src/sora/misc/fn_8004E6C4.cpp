#pragma force_active on
extern "C" void* fn_8004E6C4(void* ptr) {
    unsigned char* p = *reinterpret_cast<unsigned char**>(static_cast<char*>(ptr) + 0x24);
    return p + 0x2C0;
}
