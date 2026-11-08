#pragma force_active on

struct Ground_base { char pad[0x3c]; };

struct GimmickState {
    unsigned char kind;
    char pad1[7];
    unsigned char sub;
    char pad9[0xb];
    float pos[3];
};

struct Ground : Ground_base {
#define V(n) virtual void vf##n();
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26)
    virtual void setVisibility(unsigned long);
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41)
    virtual int fn_66_2CF8();
    V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52)
    V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62)
    V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71) V(72)
    V(73) V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82)
    V(83) V(84) V(85) V(86) V(87) V(88) V(89) V(90) V(91) V(92)
    V(93) V(94) V(95) V(96) V(97) V(98)
    virtual void disableHit(unsigned long, unsigned long);
    V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108) V(109)
    V(110) V(111) V(112) V(113) V(114) V(115) V(116) V(117) V(118)
    virtual void fn_66_10C14(int, int, int, void*);
#undef V

    char pad40[4];
    void** model44;
    unsigned char pad48[0x108];
    unsigned char state150;
    char pad151[3];
    float timer;
    char pad158[4];
    void* effArr;
    char pad160[4];
    GimmickState* state164;
    char pad168[0x18];
    char sound180[0x10];
};

extern "C" {
void setPos__14snd3DGeneratorFP5Vec3f(void*, void*);
void playSE__14snd3DGeneratorF5SndIDiii(void*, int, int, int, int);
unsigned long setEffect__5ecMgrF4EfID(void*, int);
void setParent__5ecMgrFUlPQ34nw4r3g3d6ScnMdlPCcb(void*, unsigned long, void*, const char*, bool);
void fn_8005FF8C(void*, unsigned long, int);
extern void* g_ecMgr;
extern const float lbl_66_rodata_1E0;
extern char lbl_66_data_2F18[];

void fn_66_FF18(Ground* self, float delta) {
    if (self->state164 != 0 && self->fn_66_2CF8() != 0) {
        self->timer = self->timer - delta;
        if (self->timer < lbl_66_rodata_1E0)
            self->timer = lbl_66_rodata_1E0;
        switch (self->state150) {
        case 0:
            self->fn_66_10C14(6, 0, 1, 0);
            self->setVisibility(0);
            self->disableHit(0, 0);
            self->disableHit(1, 0);
            self->state164->sub = 0;
            self->state150 = 1;
            return;
        case 1:
            if (self->state164->kind == 2) {
                self->fn_66_10C14(0, 0, 1, &self->effArr);
                self->setVisibility(1);
                setPos__14snd3DGeneratorFP5Vec3f(&self->sound180, self->state164->pos);
                playSE__14snd3DGeneratorF5SndIDiii(&self->sound180, 0x1CC5, 0, 0, -1);
                unsigned long eff = setEffect__5ecMgrF4EfID(g_ecMgr, 0x4E0003);
                fn_8005FF8C(g_ecMgr, eff, 0x14);
                setParent__5ecMgrFUlPQ34nw4r3g3d6ScnMdlPCcb(g_ecMgr, eff, *self->model44, lbl_66_data_2F18, 1);
                self->state150 = 0x13;
                return;
            }
            break;
        case 0x13:
            switch (self->state164->sub) {
            case 4: {
                unsigned long eff4;
                self->fn_66_10C14(2, 0, 1, &self->effArr);
                self->disableHit(0, 0);
                self->disableHit(1, 0);
                eff4 = setEffect__5ecMgrF4EfID(g_ecMgr, 0x4E0004);
                setParent__5ecMgrFUlPQ34nw4r3g3d6ScnMdlPCcb(g_ecMgr, eff4, *self->model44, lbl_66_data_2F18, 0);
                self->state150 = 0x1A;
                return;
            }
            case 1:
                self->fn_66_10C14(1, 0, 1, &self->effArr);
                self->disableHit(0, 0);
                self->disableHit(1, 0);
                setPos__14snd3DGeneratorFP5Vec3f(&self->sound180, self->state164->pos);
                playSE__14snd3DGeneratorF5SndIDiii(&self->sound180, 0x1CC6, 0, 0, -1);
                playSE__14snd3DGeneratorF5SndIDiii(&self->sound180, 0x1CC7, 0, 0, -1);
                self->state164->sub = 0;
                return;
            case 2:
                self->fn_66_10C14(3, 0, 1, &self->effArr);
                self->disableHit(0, 0);
                self->disableHit(1, 0);
                setPos__14snd3DGeneratorFP5Vec3f(&self->sound180, self->state164->pos);
                playSE__14snd3DGeneratorF5SndIDiii(&self->sound180, 0x1CC4, 0, 0, -1);
                self->state164->sub = 0;
                return;
            case 3:
                self->fn_66_10C14(4, 0, 1, &self->effArr);
                self->disableHit(0, 0);
                self->disableHit(1, 0);
                self->state164->sub = 0;
                break;
            }
            break;
        case 0x1A:
            break;
        }
    }
}
}
