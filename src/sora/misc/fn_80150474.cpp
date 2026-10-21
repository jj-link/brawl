#pragma force_active on
extern "C" {
extern void* g_GameGlobal;

bool fn_80150474(unsigned int arg0) {
    char* g = static_cast<char*>(g_GameGlobal);
    char* inner = *reinterpret_cast<char**>(g + 0x38);
    unsigned char flags = static_cast<unsigned char>(inner[0x8]);
    return (flags & arg0) != 0;
}
}
