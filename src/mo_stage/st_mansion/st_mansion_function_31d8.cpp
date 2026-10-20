#pragma force_active on
extern "C" {
extern const float lbl_47_rodata_48[];
extern const char lbl_47_data_AE0[];
extern void* g_ecMgr;

void fn_27_26399C(void*);
float randf__Fv();
int playSE__14snd3DGeneratorF5SndIDiii(void*, int, int, int, int);
unsigned long setEffect__5ecMgrF4EfID(void*, int);
void setParent__5ecMgrFUlPQ34nw4r3g3d6ScnMdlPCcb(
    void*, unsigned long, void*, const char*, bool);
}

struct Mansion {
    char pad0[0x44];
    void** models;
    char pad48[0x104];
    void* object;
    char pad150[0xc];
    float timer;
    unsigned char flag;
    char pad161[7];
    unsigned char* state;
    char pad16c[4];
    float delay;
    char pad174[0x14];
    float effectTimer;
    char pad18c[0x1c];
    char sound[1];
};

extern "C" void fn_47_31D8(Mansion* self, void*, const float* args) {
    const float* p = lbl_47_rodata_48;
    float delta = args[1];

    fn_27_26399C(self->object);
    float r = randf__Fv();

    if (r < p[8]) {
        playSE__14snd3DGeneratorF5SndIDiii(self->sound, 0x1b60, 0, 0, -1);
    } else if (r < p[4]) {
        playSE__14snd3DGeneratorF5SndIDiii(self->sound, 0x1b61, 0, 0, -1);
    } else if (r < p[9]) {
        playSE__14snd3DGeneratorF5SndIDiii(self->sound, 0x1b62, 0, 0, -1);
    } else {
        playSE__14snd3DGeneratorF5SndIDiii(self->sound, 0x1b63, 0, 0, -1);
    }

    switch (self->flag) {
    case 0:
        if (self->state[-1] != 2) {
            if (p[0] == self->effectTimer) {
                unsigned long effect =
                    setEffect__5ecMgrF4EfID(g_ecMgr, 0x350008);
                setParent__5ecMgrFUlPQ34nw4r3g3d6ScnMdlPCcb(
                    g_ecMgr, effect, self->models[0], lbl_47_data_AE0, true);
            }
            break;
        }
    default:
        if (p[0] == self->effectTimer) {
            unsigned long effect =
                setEffect__5ecMgrF4EfID(g_ecMgr, 0x350007);
            setParent__5ecMgrFUlPQ34nw4r3g3d6ScnMdlPCcb(
                g_ecMgr, effect, self->models[0], lbl_47_data_AE0, true);
            self->effectTimer = p[21] + p[19] * randf__Fv();
        }

        self->timer -= delta;
        if (self->timer < p[0]) {
            self->timer = p[0];
        }

        if (p[0] == self->timer) {
            self->state[0] = 1;
        } else {
            self->delay = p[17] + p[17] * randf__Fv();
        }
        break;
    }
}
