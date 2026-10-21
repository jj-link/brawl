#pragma force_active on
extern void* g_sndSystem;
extern "C" void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);

struct FnState {
    char pad[0x2F4];
    unsigned char m2F4;
};

extern "C" void fn_80105FC8(FnState* self) {
    if (*(unsigned int*)((char*)self + 0x40) & 0x100) {
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 1, -1, 0, 0, -1);
        self->m2F4 = 1;
    }
}
