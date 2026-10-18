#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern void* g_ftManager;

struct FlagByte6c {
    u8 a : 1;
    u8 b : 1;
    u8 c : 1;
    u8 d : 1;
    u8 e : 1;
    u8 f : 1;
    u8 g : 1;
    u8 h : 1;
};

extern "C" void fn_27_132174(void* obj, u32 mode) {
    u8* self = (u8*)obj;
    if (mode == 1) {
        FlagByte6c* fm = (FlagByte6c*)((u8*)g_ftManager + 0x6c);
        bool b = fm->b;
        if (b == true) {
            u32 t = (self[0x138] >> 3) & 1;
            if (t != 0) {
                return;
            }
            self[0x138] = self[0x138] | 0x8;
            return;
        }
    }
    u32 t2 = (self[0x138] >> 3) & 1;
    if (t2 != 1) {
        return;
    }
    self[0x138] = self[0x138] & ~0x8;
}
