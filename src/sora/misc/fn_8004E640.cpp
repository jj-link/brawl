#pragma force_active on
extern "C" void* fn_8004E640(void* ptr) {
    return *reinterpret_cast<char**>(static_cast<char*>(ptr) + 0x24) + 0x288;
}
