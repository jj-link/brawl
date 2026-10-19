#pragma force_active on
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef short s16;

class sndSystem {
public:
    void freeGroup(s32, s32);
};

extern "C" u8* fn_41_D5C4(u8* self);
extern "C" void* fn_41_D9AC(void* p, s16 flag);
extern "C" void fn_41_C8D0(u8* self);
extern sndSystem* g_sndSystem;

extern "C" void fn_41_D4B8(u8* self) {
    u8* entry = fn_41_D5C4(self);
    if (entry != 0) {
        void* p = *(void**)(entry + 0x14);
        if (p != 0) {
            fn_41_D9AC(p, 1);
            if (*(s32*)(entry + 0x10) >= 0) {
                g_sndSystem->freeGroup(*(s32*)(entry + 0x10), 0xc);
            }
            fn_41_C8D0(entry);
        }
    }
}
