#pragma force_active on
struct SoundAction {
    unsigned char pad00[0x40];
    unsigned char state;
    unsigned char pad41[0x1B];
    unsigned char enabled;
    unsigned char pad5D[7];
    int soundId;
    unsigned char pad68[4];
    float frame;
};

extern "C" {
extern void* g_sndSystem;
void fn_800741EC(void*, int, int);

void fn_27_242638(SoundAction* self) {
    void* soundSystem = g_sndSystem;
    if (self->enabled) {
        fn_800741EC(soundSystem, self->soundId, (int)self->frame);
        self->state = 4;
    }
}
}
