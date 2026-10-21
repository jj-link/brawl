#pragma force_active on
extern "C" {
int fn_800B5854(void* p, int a, int b, int c, int d);
void playSE__9sndSystemF5SndIDiiii(void* self, int id, int a, int b, int c, int d);
}

extern void* g_sndSystem;

struct SoraObj4 {
    char pad[4];
    void* m4;
};

extern "C" void fn_801057DC(SoraObj4* self) {
    fn_800B5854(self->m4, 1, 1, 1, 0);
    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 6, -1, 0, 0, -1);
}
