#pragma force_active on
typedef unsigned int u32;

struct gfPadStatus {
    u32 words[16];
};

struct MenuInput {
    char unused[0x10];
    u32 buttons;
    char rest[0x94];
};

struct Menu {
    char unused[0x44];
    int port;
    int secondPort;
    int difficulty;
    int timer;
    MenuInput input[2];
    char unused1[0x24];
    int state;
    char unused2[0x170];
    bool accepted;
};

extern "C" {
extern void* g_gfPadSystem;
extern void* g_sndSystem;

void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(void*, int, gfPadStatus*);
void init__11gfPadStatusFv(gfPadStatus*);
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);

void fn_32_574(Menu* self) {
    if (self->timer > 0) {
        if (--self->timer > 0) return;
    }
    if (self->state != 2) return;

    u32 buttons[2];
    gfPadStatus status[2];

    for (int i = 0; i < 2; ++i) {
        buttons[i] = self->input[i].buttons;
        getSysPadStatus__11gfPadSystemFiP11gfPadStatus(
            g_gfPadSystem, self->port, &status[0]);

        if (self->secondPort >= 0)
            getSysPadStatus__11gfPadSystemFiP11gfPadStatus(
                g_gfPadSystem, self->secondPort, &status[1]);
        else
            init__11gfPadStatusFv(&status[1]);

        int difficulty = self->difficulty;
        if ((buttons[i] & 8) && difficulty > 0) --difficulty;
        if ((buttons[i] & 4) && difficulty < 4) ++difficulty;

        if (difficulty != self->difficulty) {
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
            self->difficulty = difficulty;
        }

        if (status[i].words[3] & 0x100) {
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x13, -1, 0, 0, -1);
            self->state = 3;
            self->accepted = true;
        }

        if (status[i].words[3] & 0x200) {
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 2, -1, 0, 0, -1);
            self->state = 3;
            self->accepted = false;
        }
    }
}
}
