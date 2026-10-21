#pragma force_active on
extern "C" void* fn_8004E5F8(void* arg) {
    void* ptr = *reinterpret_cast<void**>(static_cast<char*>(arg) + 0x24);
    return static_cast<char*>(ptr) + 0x1c;
}
