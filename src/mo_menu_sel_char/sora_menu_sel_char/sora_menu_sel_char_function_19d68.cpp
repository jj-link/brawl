#pragma force_active on
extern "C" void* fn_10_19D68(void* arg) {
    char* first = *reinterpret_cast<char**>(static_cast<char*>(arg) + 0x9C);
    return *reinterpret_cast<void**>(first + 0x1B0);
}
