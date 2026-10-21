#pragma force_active on
extern "C" {
    extern void* g_GameGlobal;

    unsigned int fn_800557D8() {
        void* ptr = *static_cast<void**>(g_GameGlobal);
        unsigned char val = *reinterpret_cast<unsigned char*>(static_cast<char*>(ptr) + 0x28);
        unsigned int bit = (val >> 4) & 1;
        unsigned int negated = 0u - bit;
        return (negated | bit) >> 31;
    }
}
