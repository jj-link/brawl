#pragma force_active on

struct AiMgr {
    char pad[0x84];
    signed char teams[14];
    char pad2[0x100 - 0x92];
    void* unk100;
};

struct State {
    char pad[0x50];
    unsigned int flags;
    char pad54[0x5C - 0x54];
    float pos;
    char pad60[0xBC - 0x60];
    int unkBC;
    char padC0[0xC8 - 0xC0];
    int unkC8;
    int unkCC;
    char padD0[0x1BA - 0xD0];
    unsigned char unk1BA;
};

struct Self {
    char pad[0x3C];
    unsigned short unk3C;
    char pad3E[0x42 - 0x3E];
    signed char id;
    char pad43[0x90 - 0x43];
    char params[0x110 - 0x90];
    signed char unk110;
    char pad111;
    unsigned char unk112;
};

struct Res {
    char pad[4];
    unsigned char unk4;
};

extern AiMgr* g_aiMgr;
extern const float lbl_27_rodata_2CF0[];

extern "C" signed char fn_27_1FE478();
extern "C" State* fn_27_1F1F58(signed char*);
extern "C" int fn_27_1F2D2C(AiMgr*, int);
extern "C" float fn_27_21F45C(void*, State*);
extern "C" float fn_27_21F434(void*, State*);
extern "C" float fn_27_21F484(void*, State*);
extern "C" int fn_27_1EFE3C(AiMgr*, int, int, float, int, float, float);
extern "C" float fn_27_20B898(State*, signed char*, float);
extern "C" Res* fn_27_21C900(void*, float*, float*);

static inline signed char getTeam(AiMgr* m, signed char i) {
    if (i < 0 || (unsigned)i >= 14)
        return -1;
    return m->teams[i];
}

static inline signed char getTeamI(AiMgr* m, int i) {
    if (i < 0 || (unsigned)i >= 14)
        return -1;
    return m->teams[i];
}

extern "C" signed char fn_27_1FE1C0(Self* self, float* out, int check) {
    float bestDist;
    const float* c = lbl_27_rodata_2CF0;
    signed char r = fn_27_1FE478();
    if (r != self->id)
        return r;
    State* me = fn_27_1F1F58(&self->id);
    int i;
    int best = self->id;
    bestDist = c[0x1F4 / 4];
    unsigned int bestFlag = 0;
    bool solo = getTeam(g_aiMgr, self->id) == 1;
    State* other;
    for (i = 0; i < 7; i++) {
        struct { signed char value; char pad[3]; } tmp;
        tmp.value = i;
        other = fn_27_1F1F58(&tmp.value);
        unsigned int flag = 1;
        if (i == self->id)
            continue;
        if ((other->flags & 0x8000) && !(other->flags & 0x40000000))
            continue;
        if (other->unkCC == me->unkCC)
            continue;
        if (solo) {
            if (getTeamI(g_aiMgr, i) == 1 &&
                self->unk110 == fn_27_1F2D2C(g_aiMgr, i)) {
                if (bestFlag == 1)
                    continue;
                flag = 0;
            }
        }
        if (check) {
            float a;
            if (self->unk3C & 0x20)
                a = fn_27_21F45C(self->params, me);
            else
                a = fn_27_21F434(self->params, me);
            AiMgr* m = g_aiMgr;
            if (!fn_27_1EFE3C(m, me->unkBC, other->unkBC, me->pos, me->unkC8,
                              fn_27_21F484(self->params, me), a))
                continue;
        }
        signed char tmp2 = i;
        float d = fn_27_20B898(me, &tmp2, c[0]);
        if (other->unk1BA == 15)
            d += (c[0x1F8 / 4]);
        if (bestDist > d || (flag && bestFlag == 0)) {
            bestDist = d;
            best = i;
            bestFlag = flag;
        }
    }
    if (self->unk112 != 0 && best == self->id) {
        Res* res = fn_27_21C900(g_aiMgr->unk100, &me->pos, &bestDist);
        if (res)
            best = res->unk4 + 14;
    }
    if (out && best != self->id)
        *out = bestDist;
    return (signed char)best;
}
