#pragma force_active on
extern "C" void* fn_8004E588(void* ptr) {
    unsigned char* p = *reinterpret_cast<unsigned char**>((unsigned char*)ptr + 0x24);
    return p + 0x24C;
}
