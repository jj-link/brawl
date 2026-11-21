#include <ft/ft_manager.h>
#include <snd/snd_system.h>

#pragma force_active on

struct Object_vptr_0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual bool slot7();

    char pad04[4];
    int value8;
    int valueC;
};

struct Object_vptr_3c_base {
    char pad[0x3c];
};

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
    virtual bool slot43();
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
};

struct RulePlayer {
    char pad00[0x19];
    unsigned char inactive;
    char pad1A[2];
    unsigned char stock;
    char pad1D[0x1d];
    unsigned short damage;
    char pad3C[0x20];
};

struct StageBits {
    unsigned char group : 1;
    unsigned char index : 7;
};

struct RuleData {
    char pad00[8];
    unsigned char mode;
    char pad09[5];
    unsigned char difficulty;
    char pad0F;
    union {
        unsigned char stage;
        StageBits stageBits;
    };
    char pad11[3];
    unsigned char flag14;
    char pad15[3];
    unsigned char delay;
    char pad19[7];
    int time;
    char pad24[0x5c];
    RulePlayer players[1];
};

struct ResultPlayer {
    char pad00[0x25];
    unsigned char type;
    char pad26[0xa];
    unsigned short value30;
    char pad32[2];
    int value34;
    char pad38[0x274];
};

struct ResultData {
    unsigned char pad00[2];
    unsigned char flag2;
    char pad03[0x1375];
    unsigned char result;
};

struct RecordBits {
    unsigned int level : 2;
    unsigned int score : 30;
};

struct RecordTable {
    char pad[0x32c];
    unsigned int scores[2][3][51];
};

struct Melee : Object_vptr_3c {
    unsigned char state;
    unsigned char pad41;
    unsigned char flag42;
    unsigned char flag43;
    RuleData* rules;
    void* ptr48;
    char pad4C[8];
    Object_vptr_0* ptr54;
    char pad58[0x1c];
    unsigned char flag74;
    unsigned char flag75;
    char pad76[0x56];
    ResultData* result;
    unsigned char flagD0;
    char padD1[4];
    unsigned char flagD5;
    unsigned char flagD6;
    char padD7[4];
    unsigned char flagDB;
    char padDC[2];
    unsigned char flagDE;
    unsigned char flagDF;
    unsigned int timeE0;
    char padE4[4];
    int timeE8;
    float timeEC;
    char padF0[8];
    int valueF8;
    int counterFC;
    int value100;
    int playerCount;
    char pad108[0xac];
    int value1B4;
    char pad1B8[0x6c];
    unsigned char flag224;
    char pad225[3];
    int value228;
    int value22C;
    int score;
    bool success;
    char pad235[0x1f];
    int resultCode;
    unsigned char record;
};

extern "C" {
extern Object_vptr_3c* lbl_27_bss_5668;
extern unsigned char lbl_27_bss_59A0[];
extern const float lbl_27_rodata_4028;
extern void* g_gfApplication;
extern void* g_GameGlobal;
extern void* g_IfMngr;

void fn_27_109364(ftManager*);
void fn_27_242418(void*);
void fn_27_24814C(Melee*, ResultData*, float);
int fn_27_24857C(Melee*);
void fn_27_24858C(Melee*);
int fn_27_2485A8(Melee*);
void fn_27_24A1F0(Melee*);
int fn_27_24A338(Melee*);
void fn_27_24A86C(Melee*);
void fn_27_24C498(Melee*, int, unsigned char);
int fn_27_24C91C(Melee*);
void fn_27_24CF90(Melee*);
void fn_27_24D198(Melee*, unsigned int, int);
void fn_27_24D6A0(Melee*);
void fn_27_24D9D8(Melee*);
void fn_27_24DD38(ResultData*);
char* fn_8004E5C4(void*);
float fn_8004E94C(void*);
}

extern "C" void fn_27_249068(Melee* self) {
    unsigned char stage;
    int group;

    if (self->flag43 != 1 && self->flag42 != 1) {
        switch (self->state) {
        case 1: {
            if (lbl_27_bss_5668 != 0) {
                float time;
                if (self->timeE0 != 0)
                    time = (float)self->timeE0 - self->timeEC;
                else
                    time = lbl_27_rodata_4028;
                lbl_27_bss_5668->slot79(time);
            }

            if (self->flag224)
                fn_27_24CF90(self);

            if (self->flag75 && lbl_27_bss_59A0[4]) {
                lbl_27_bss_59A0[4] = 0;
                fn_27_24D198(self, lbl_27_bss_59A0[5],
                             *(unsigned short*)(lbl_27_bss_59A0 + 6));
            }

            fn_27_24A1F0(self);
            self->slot29();
            fn_27_24A86C(self);
            self->slot42();

            float delta;
            if (*(unsigned int*)((char*)g_gfApplication + 0xec) >> 27)
                delta = lbl_27_rodata_4028;
            else
                delta = fn_8004E94C(g_GameGlobal);
            fn_27_24814C(self, self->result, delta);

            if (self->flagDF && self->ptr54 && self->ptr54->slot7()) {
                self->resultCode = self->ptr54->valueC;
                self->result->result = self->ptr54->value8;
            } else {
                if (!self->flagD5)
                    break;

                if (self->slot43()) {
                    self->slot44();
                } else if (fn_27_24A338(self)) {
                    int value = self->value100;
                    RuleData* rules = self->rules;
                    self->resultCode = value;
                    if (!rules->flag14) {
                        if ((unsigned int)((rules->mode >> 2) & 0x3f) == 7) {
                            unsigned char result = 4;
                            if (value == 4)
                                result = 5;
                            self->result->result = result;
                        } else if (!self->result->flag2) {
                            self->result->result = 2;
                        } else {
                            self->result->result = 3;
                        }
                    } else {
                        self->result->result = 4;
                    }
                } else {
                    int expired = 0;
                    if (self->flagD0 &&
                        (float)self->timeE0 - self->timeEC <= lbl_27_rodata_4028)
                        expired = 1;

                    if (expired) {
                        if ((unsigned int)((self->rules->mode >> 2) & 0x3f) == 7 &&
                            self->value228 == 1)
                            self->valueF8 = 4;
                        self->resultCode = self->valueF8;
                        self->result->result = 1;
                    } else if (fn_27_24C91C(self)) {
                        self->resultCode = self->value1B4;
                        self->result->result = 5;
                    } else {
                        fn_27_24D6A0(self);
                        fn_27_24D9D8(self);
                        break;
                    }
                }
            }

            self->flagD5 = 0;
            self->slot45();

            if (self->flagD6) {
                self->rules->time = self->timeE8;
                for (int i = 0; i < self->playerCount; i++) {
                    int entry = g_ftManager->getEntryId(i);
                    if (g_ftManager->isValidEntryId(entry) &&
                        !self->rules->players[i].inactive) {
                        ftOwner* owner = g_ftManager->getOwner(entry);
                        self->rules->players[i].damage = (short)owner->getDamage();
                        self->rules->players[i].stock = owner->getStockCount();
                    }
                }
            }

            if ((unsigned int)((self->rules->mode >> 2) & 0x3f) == 7) {
                self->success = self->value228 == self->result->result;

                if (self->rules->stage == 0x16) {
                    ResultPlayer* p;
                    self->score = 0;
                    int i = 0;
                    int offset = 0;
                    for (; i < self->playerCount; offset += 0x2ac, i++) {
                        p = (ResultPlayer*)((char*)self->result + offset);
                        if (!p->type)
                            self->score += p->value34;
                    }
                    if (self->score == 0) {
                        self->success = 0;
                        self->resultCode = 3;
                    }
                }

                if (self->success) {
                    RuleData* rules = self->rules;
                    stage = rules->stage;
                    int difficulty = (rules->difficulty >> 5) & 7;
                    group = rules->stageBits.group;
                    unsigned int* record = &((RecordTable*)fn_8004E5C4(g_GameGlobal))
                                                ->scores[group][difficulty][stage & 0x7f];
                    unsigned int level = difficulty + 1;
                    if ((*record >> 30) < level)
                        ((RecordBits*)record)->level = level;

                    switch (self->value22C) {
                    case 1: {
                        int score = 0x34bbf;
                        if (self->timeE8 < score)
                            score = self->timeE8;
                        self->score = score;
                        unsigned int old = *record & 0x3fffffff;
                        if (old == 0 || old > (unsigned int)score) {
                            ((RecordBits*)record)->score = self->score;
                            self->record = 1;
                        }
                        break;
                    }
                    case 2: {
                        ResultPlayer* p;
                        self->score = 0;
                        int i = 0;
                        int offset = 0;
                        for (; i < self->playerCount; offset += 0x2ac, i++) {
                            p = (ResultPlayer*)((char*)self->result + offset);
                            if (!p->type)
                                self->score += p->value34;
                        }
                        int score = 0x05f5e0ff;
                        if (self->score < score)
                            score = self->score;
                        self->score = score;
                        unsigned int old = *record & 0x3fffffff;
                        if (old == 0 || old < (unsigned int)score) {
                            ((RecordBits*)record)->score = self->score;
                            self->record = 1;
                        }
                        break;
                    }
                    case 3: {
                        ResultPlayer* p;
                        self->score = 0;
                        int i = 0;
                        int offset = 0;
                        for (; i < self->playerCount; offset += 0x2ac, i++) {
                            p = (ResultPlayer*)((char*)self->result + offset);
                            if (p->type == 1)
                                self->score += p->value30;
                        }
                        int score = 0x05f5e0ff;
                        if (self->score < score)
                            score = self->score;
                        self->score = score;
                        unsigned int old = *record & 0x3fffffff;
                        if (old == 0 || old < (unsigned int)score) {
                            ((RecordBits*)record)->score = self->score;
                            self->record = 1;
                        }
                        break;
                    }
                    }
                }
                unsigned char result = 8;
                if (self->success)
                    result = 7;
                self->result->result = result;
            }

            fn_27_109364(g_ftManager);
            fn_27_24C498(self, self->resultCode, self->record);
            fn_27_24DD38(self->result);
            self->slot40();
            if (self->ptr48)
                fn_27_242418(self->ptr48);
            self->state = 2;
            self->flag74 = 1;
            self->pad[0x2c] &= ~2;
            break;
        }

        case 2:
            if (self->counterFC < self->rules->delay) {
                self->counterFC++;
                if (self->flagDE && self->counterFC == 0x48)
                    g_sndSystem->playSE((SndID)0xd6, -1, 0, 0, -1);
            } else {
                if (g_IfMngr &&
                    *(int*)((char*)*(void**)((char*)g_IfMngr + 0x44) + 4))
                    break;
                if (self->flagDB && fn_27_24857C(self)) {
                    fn_27_24858C(self);
                    fn_27_2485A8(self);
                    self->state = 3;
                } else {
                    self->state = 5;
                    self->pad[0x2c] |= 2;
                }
            }
            break;

        case 3:
            if (fn_27_2485A8(self)) {
                self->state = 5;
                self->pad[0x2c] |= 2;
            }
            break;
        }
    }
}
