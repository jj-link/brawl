#pragma force_active on
extern "C" void* fn_8004E604(void* object) {
    unsigned char* ptr = *reinterpret_cast<unsigned char**>((unsigned char*)object + 0x24);
    return ptr + 0x2C8;
}
