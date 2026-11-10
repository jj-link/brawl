#pragma force_active on

extern "C" {
void fn_800B9F90(void* out, void* a, int flag);
int fn_800BA1FC(int arg0);
void setFrameMatCol__8MuObjectFf(void* obj, float frame);
void playSE__9sndSystemF5SndIDiiii(void* th, int sndID, int a1, int a2, int a3, int a4);
extern void* g_sndSystem;
extern const float lbl_805A22B0;
extern const float lbl_805A22BC;
}

struct PadStat {
    int w[16];
};

struct Self {
    char pad[0x40];
    void* f40;
    char pad44[0x10];
    int f54;
    char pad58[8];
    unsigned int f60;
    char pad64[0x98];
    int ffc;
    unsigned char byte100;
    char pad101[3];
    int f104;
    char pad108[8];
    int f110;
    int f114;
    char pad118[0xc];
    int f124;
};

extern "C" int fn_800BFCF4(Self* self) {
    unsigned int flags60;
    PadStat status;
    PadStat result;
    fn_800B9F90(&result, &self->f54, 0);
    status = result;
    int cnt = self->f110;
    if (cnt < 0)
        return self->f104;
    int newv = self->f114 + 1;
    self->f114 = newv;
    if (newv < cnt)
        return self->f104;
    if (self->ffc == 1) {
        flags60 = self->f60;
        if ((flags60 & 1) && self->byte100 == 0) {
            float f = lbl_805A22B0;
            setFrameMatCol__8MuObjectFf(self->f40, f);
            self->byte100 = 1;
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
        }
        if ((flags60 & 2) && self->byte100 != 0) {
            float f = lbl_805A22BC;
            setFrameMatCol__8MuObjectFf(self->f40, f);
            self->byte100 = 0;
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
        }
    }
    unsigned int flags;
    int ffc = self->ffc;
    if (ffc == 3)
        return self->f104;
    flags = status.w[3];
    if ((flags & 0x1100) || (flags & 0x200)) {
        int sndid;
        unsigned char pad25;
        if (ffc == 1) {
            if (flags & 0x200) {
                pad25 = 0;
                sndid = 2;
            } else {
                pad25 = self->byte100;
                if (pad25 != 0) {
                    sndid = 0x13;
                } else {
                    sndid = 1;
                }
            }
        } else {
            pad25 = 0;
            sndid = ((flags >> 9) & 1) + 1;
        }
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, sndid, 0x10000, 0, 0, -1);
        self->byte100 = pad25;
        if (pad25 != 0) {
            int r = fn_800BA1FC(0x1300);
            self->f124 = r;
            if (r < 0)
                self->f124 = 0;
        }
        return 2;
    }
    return self->f104;
}