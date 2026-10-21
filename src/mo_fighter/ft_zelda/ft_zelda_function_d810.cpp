#pragma force_active on
typedef signed short s16;
typedef unsigned char u8;
typedef int s32;

struct ZeldaSubFlags {
    u8 pad[5];
    u8 flag : 1;
    u8 rest : 7;
    u8 stopFlag;
};

extern "C" {
void fn_104_D7C0(void* sub, void* arg);
s16* fn_104_DC48(s16* destination, const s16* source);
s32 fn_104_D8A0(void* object, s16* data, void* arg);
}

extern "C" void fn_104_D810(void* self, const s16* source, void* arg) {
    s16 local[4];
    u8* base = static_cast<u8*>(self);
    ZeldaSubFlags* sub = reinterpret_cast<ZeldaSubFlags*>(base + 0xC);

    if ((source[0] & 1) != 0) {
        bool enabled = sub->flag;
        if (enabled == true && sub->stopFlag == 0) {
            fn_104_D7C0(sub, arg);
        }
    }

    fn_104_DC48(local, source);
    fn_104_D8A0(base + 4, local, arg);
}
