#pragma force_active on
extern "C" {
void fn_12_588(void*, int);
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
extern void* g_sndSystem;
}

struct GameOver {
    char pad0[0x58];
    int x58;
    int x5C;
    int x60;
    int x64;
    char pad68[0xB0];
    int x118;
    int x11C;
    int x120;
    int x124;
    int x128;
};

extern "C" void fn_12_BEC(GameOver* self) {
    fn_12_588(self, 3);

    self->x118 = self->x60 - self->x64;
    int delta = self->x118 - self->x60;
    self->x11C = delta / 120;

    if (self->x11C == 0) {
        if (self->x11C == 0) {
            if (delta > 0)
                self->x11C = 1;
            else
                self->x11C = -1;
        }
    }

    delta = self->x5C - self->x58;
    self->x120 = delta / 120;

    if (self->x120 == 0) {
        if (delta > 0)
            self->x120 = 1;
        else
            self->x120 = -1;
    }

    self->x128 = 0;
    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x13, -1, 0, 0, -1);
}
