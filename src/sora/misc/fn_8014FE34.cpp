#pragma force_active on

extern void* g_GameGlobal;

extern "C" void* fn_8014FE34() {
    return *reinterpret_cast<unsigned char**>(
        static_cast<unsigned char*>(g_GameGlobal) + 0x34) + 0x2F;
}
