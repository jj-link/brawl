#pragma force_active on
typedef unsigned char u8;
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
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
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
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79(float);
    u8 state;
    u8 pad41;
    u8 flag42;
    u8 flag43;
    char pad44[4];
    void* ptr48;
    char pad4c[0x28];
    u8 flag74;
    char pad75[0x57];
    float timer;
};
struct IfCenter { char pad[4]; int state; };
struct IfManager { char pad[0x44]; IfCenter* center; };
extern "C" {
extern void* g_GameGlobal;
extern IfManager* g_IfMngr;
extern void* g_ftManager;
extern Object_vptr_3c* lbl_27_bss_5668;
extern const float lbl_27_rodata_4058;
float fn_8004E94C(void*);
void fn_800DDCF8(void*, unsigned int);
void fn_800DE508(void*, int);
void fn_27_242418(void*);
void fn_27_109364(void*);
}
extern "C" void fn_27_24E04C(Object_vptr_3c* self) {
    if (self->flag43 != 1 && self->flag42 != 1) {
        self->timer -= fn_8004E94C(g_GameGlobal);
        if (self->timer < lbl_27_rodata_4058)
            self->timer = lbl_27_rodata_4058;
        if (lbl_27_bss_5668)
            lbl_27_bss_5668->slot79(self->timer);
        switch (self->state) {
        case 3:
            break;
        case 1:
            fn_800DDCF8(g_IfMngr->center, (unsigned int)self->timer);
            if (lbl_27_rodata_4058 == self->timer) {
                fn_800DE508(g_IfMngr->center, 4);
                if (self->ptr48)
                    fn_27_242418(self->ptr48);
                self->state = 2;
                self->slot29();
                fn_27_109364(g_ftManager);
                self->flag74 = 1;
                self->pad[0x2c] &= ~2;
            }
            break;
        case 2:
            if (g_IfMngr->center->state == 0) {
                self->state = 5;
                self->pad[0x2c] |= 2;
            }
            break;
        }
    }
}