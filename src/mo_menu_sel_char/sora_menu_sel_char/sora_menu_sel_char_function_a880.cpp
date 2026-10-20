#pragma force_active on
typedef unsigned int u32;

struct gfPadStatus {
    char pad0[0xc];
    u32 buttons;
    char pad1[0x28];
    signed char error;
    char pad2[7];
};

struct Player {
    char pad0[0x1a8];
    void* selector;
    char pad1[0x30];
    int port;
};

struct Menu {
    char pad0[0x44];
    Player* players[4];
    char pad1[0x594];
    int active;
    char pad2[0x5c];
    int count;
    int state;
};

extern "C" {
extern void* g_sndSystem;
extern void* g_gfPadSystem;

int fn_10_AA74(Menu*);
void fn_10_EFA8(Menu*, int);
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(void*, int, gfPadStatus*);
int fn_10_1B2A4(void*, void*, void*);
int fn_10_F344(Menu*);
void fn_10_13C80(Player*);
void fn_10_4A54(Menu*, int, int, int);

int fn_10_A880(Menu* self) {
    int result = 0;
    int enabled = fn_10_AA74(self);

    if (enabled) {
        if (self->active == 0) {
            fn_10_EFA8(self, 1);
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x1eec, -1, 0, 0, -1);
        }
    } else {
        if (self->active != 0)
            fn_10_EFA8(self, 0);
    }

    if (enabled && self->state < 0) {
        int i;
        gfPadStatus status;

        for (i = 0; i < self->count; ++i) {
            int port = self->players[i]->port;
            if (port >= 0) {
                getSysPadStatus__11gfPadSystemFiP11gfPadStatus(
                    g_gfPadSystem, port, &status);

                if (status.error == 0) {
                    result = 0;
                    if (status.buttons & 0x1000) {
                        result = 1;
                    } else if (status.buttons & 0x100) {
                        if (fn_10_1B2A4(self->players[i]->selector, 0, 0) == 8)
                            result = 1;
                    }

                    if (result) {
                        fn_10_F344(self);
                        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 1, -1, 0, 0, -1);
                        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x16, -1, 0, 0, -1);
                        break;
                    }
                }
            }
        }

        if (i < self->count) {
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 1, -1, 0, 0, -1);
            for (int j = 0; j < self->count; ++j)
                fn_10_13C80(self->players[j]);
            fn_10_4A54(self, 1, i, 0);
        }
    }

    return result;
}
}
