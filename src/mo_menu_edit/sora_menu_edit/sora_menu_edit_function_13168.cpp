#pragma force_active on
extern "C" void* fn_5_13168(void* object) {
    char* base = static_cast<char*>(object);

    void* p1 = *reinterpret_cast<void**>(base + 0x1ac);
    void* p2 = *reinterpret_cast<void**>(static_cast<char*>(p1) + 0x1d3c);
    void* p3 = *reinterpret_cast<void**>(static_cast<char*>(p2) + 0x35c);
    void* value = *reinterpret_cast<void**>(p3);

    if (*reinterpret_cast<unsigned char*>(static_cast<char*>(value) + 0x1a4)) {
        return *reinterpret_cast<void**>(static_cast<char*>(value) + 0x48);
    }
    return 0;
}
