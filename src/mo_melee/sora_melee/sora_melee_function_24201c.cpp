#pragma force_active on

struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void processDefault();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void processPreMapCorrection();
    virtual void slot5();
    virtual void slot6();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void slot12();
    virtual void processEffect();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual int slot69();
    virtual void slot70();
    virtual void slot71();
    virtual int slot72();
    virtual unsigned int slot73();
    virtual void slot74(int*, float*);
    virtual void slot75(float, int, int);
};

struct Info { char pad[0x5c]; int bgm; };

struct Self {
    char pad[0x40];
    unsigned char state;
    char pad41[3];
    Info* info;
    int id;
    unsigned char isStep;
    char pad4d[3];
    int handle;
    char pad54[4];
    int fade;
    unsigned char f5c;
    unsigned char f5d;
    unsigned char f5e;
    char pad5f;
    int timer;
};

extern "C" {
extern void* g_sndSystem;
extern Object_vptr_3c* lbl_27_bss_5668;
extern const float lbl_27_rodata_3DB8;
extern char* lbl_805A01D8;
void fn_80073F84(void*, int);
int fn_80074018(void*, int, int);
int fn_80074184(void*, int);
void fn_800741EC(void*, int, int);
void fn_80078EB8(void*, int, int);
void fn_800790FC(void*, int);
int fn_80079104(void*, int, int, int);
int fn_800791C4(void*);
void fn_800791D4(void*, int);
unsigned short fn_800791F0(void*);
}

extern "C" void fn_27_24201C(Self* self) {
    switch ((int)self->state) {
    case 0:
        if (self->f5e == 1) self->state = 1;
        break;
    case 1: {
        int r5;
        int r6;
        int b = self->info->bgm;
        if (b != 0) {
            unsigned int hi = (unsigned int)b >> 24;
            if (hi == 0xff) {
                self->id = b & 0xffffff;
                r5 = 0;
                r6 = 0;
            } else {
                self->id = hi;
                r5 = 0;
                r6 = self->info->bgm & 0xffffff;
            }
        } else if (lbl_27_bss_5668 != 0) {
            self->id = lbl_27_bss_5668->slot69();
            r5 = lbl_27_bss_5668->slot72();
            r6 = 0;
        } else {
            self->id = 0;
            r5 = 0;
            r6 = 0;
        }
        self->isStep = self->id < 0x100;
        if (self->f5e == 1) r5 = -1;
        if (self->isStep) {
            self->handle = fn_80079104(lbl_805A01D8, self->id, r5, r6);
            self->timer = fn_800791F0(lbl_805A01D8);
            if ((unsigned int)self->timer == 0xffff) self->timer = 0xb4;
            self->state = 2;
        } else {
            *(int*)(lbl_805A01D8 + 0x174) = 0x2d;
            self->handle = self->id;
            if (!fn_80074018(g_sndSystem, self->id, 1)) self->handle = -1;
            self->state = 2;
        }
        if (self->f5e == 1) self->timer = 0x3c;
        break;
    }
    case 2:
        if (self->handle >= 0) {
            if (self->isStep) {
                if (fn_800791C4(lbl_805A01D8) != 0) goto set3;
                break;
            } else {
                if (fn_80074184(g_sndSystem, self->id) == 0) break;
            }
        }
    set3:
        self->state = 3;
        break;
    case 3:
        if (self->f5c == 1) {
            if (self->timer != 0) {
                self->timer--;
                break;
            }
            if (self->handle >= 0) {
                if (self->isStep) fn_800791D4(lbl_805A01D8, 0);
                else fn_800741EC(g_sndSystem, 0, 0);
            }
            self->state = 4;
        }
        break;
    case 4:
        if (self->f5d == 1) {
            if (self->handle >= 0) {
                if (self->isStep) fn_800790FC(lbl_805A01D8, self->fade);
                else fn_80073F84(g_sndSystem, self->fade);
            }
            self->f5c = 0;
            self->state = 5;
        }
        if (lbl_27_bss_5668 != 0 && lbl_27_bss_5668->slot73() == 1) {
            int a;
            float f;
            lbl_27_bss_5668->slot74(&a, &f);
            if (self->handle >= 0 && self->isStep)
                fn_80078EB8(lbl_805A01D8, a, (int)f);
            lbl_27_bss_5668->slot75(lbl_27_rodata_3DB8, 0, 0);
        }
        break;
    case 5:
        if (self->f5d == 1) {
            self->state = 0;
            self->f5d = 0;
        }
        break;
    }
}
