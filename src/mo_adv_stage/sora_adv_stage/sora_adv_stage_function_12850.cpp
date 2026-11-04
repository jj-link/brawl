#include <types.h>
#pragma force_active on

struct Vec {
    float x, y, z;
    Vec(const Vec& v) : x(v.x), y(v.y), z(v.z) {}
};

struct Entry {
    u8 active, pending;
    u8 pad[2];
    void* enemy;
    u32 id;
    int state;
    float time, delay, other;
};

struct Config {
    u8 pad[0x4C];
    float base, random;
    u32 scale;
    float interval, chance;
    u8 pad60[5];
    u8 minimum, count;
    u8 pad67[3];
    u8 enabled;
    u8 pad6B;
    u32 normal, rare;
    u8 pad74[12];
    u8 trigger[4];
};

struct Self {
    u8 pad[0x90];
    Config* config;
    Entry* entries;
    u8 pad98[0x10];
    float time;
    int count;
    u8 started, done;
};

struct GameData {
    u8 pad[0x5FD];
    u8 level;
    u8 pad5FE[0x4916 - 0x5FE];
    u8 adjustment;
};

struct Game {
    u8 pad[0x30];
    GameData* data;
};

extern "C" {
extern Game* g_GameGlobal;
extern void* lbl_41_bss_30;
extern void* lbl_40_bss_15C;
extern void* g_stTriggerMng;
extern const float lbl_40_rodata_1B0;
extern const float lbl_40_rodata_1B4;
extern const double lbl_40_rodata_1B8;

float randf__Fv();
void fn_40_12F14(Self*, u32, int);
void* getInstance__9emManagerFv();
int fn_41_D0A8(void*, u32);
void fn_40_12C54(Self*, Entry*);
float fn_8004E94C(Game*);
Vec getPos__23soExternalValueAccesserFP11StageObject(void*);
int isCanGetRareItem__23emExternalValueAccesserFP5Enemy(void*);
void fn_40_6240(void*, u32, Vec*);
void setTriggerFlag__12stTriggerMngFP13stTriggerData(void*, void*);
}

inline u8 difficulty()
{
    int level = g_GameGlobal->data->level;
    int adjustment = g_GameGlobal->data->adjustment;
    int minimum = level - 5;
    int n = level - adjustment;

    if (n < minimum)
        n = minimum;
    if (n < 0)
        n = 0;
    if (n > 14)
        n = 14;

    return n;
}

inline void item(u32 id, Vec* pos)
{
    if (id != 0xFFFFFFFF && lbl_40_bss_15C)
        fn_40_6240(lbl_40_bss_15C, id, pos);
}

extern "C" void fn_40_12850(Self* self)
{
    if (self->done == 1)
        return;

    Entry* e;
    Config* cfg;
    u32 i;

    for (i = 0; i < (cfg = self->config)->count; ++i) {
        e = &self->entries[i];

        if (e->active) {
            switch (e->state) {
            case 1: {
                u8 d = difficulty();
                float r = randf__Fv();
                float offset = (float)(cfg->scale * d);
                float delay = cfg->base + cfg->random * r;

                e->delay = delay + offset;
                e->time = lbl_40_rodata_1B0;
                e->other = lbl_40_rodata_1B0;
                e->state = 2;
            }
            case 2:
                if (e->time > e->delay)
                    e->state = 3;
                break;

            case 3:
                fn_40_12F14(self, i, 0);

            case 4:
                if (lbl_41_bss_30) {
                    if (fn_41_D0A8(getInstance__9emManagerFv(), e->id)
                        && self->config->enabled) {
                        fn_40_12C54(self, e);
                    }
                }
                break;
            }

            e->time += fn_8004E94C(g_GameGlobal);
        }

        if (self->entries[i].pending == 1) {
            void* enemy = self->entries[i].enemy;
            Vec tmp = getPos__23soExternalValueAccesserFP11StageObject(enemy);
            Vec pos(tmp);
            pos.y += lbl_40_rodata_1B4;

            if (self->config->normal != 0xFFFFFFFF) {
                if (!isCanGetRareItem__23emExternalValueAccesserFP5Enemy(enemy))
                    item(self->config->normal, &pos);
                else
                    item(self->config->rare, &pos);
            }

            self->entries[i].pending = 0;
        }
    }

    if (!self->started
        && self->count < cfg->count
        && self->time > cfg->interval) {
        if (randf__Fv() < self->config->chance)
            self->started = 1;
        else
            self->time = lbl_40_rodata_1B0;
    }

    u8 d = difficulty();

    if (d < self->config->minimum - 1) {
        self->done = 1;
        setTriggerFlag__12stTriggerMngFP13stTriggerData(
            g_stTriggerMng, self->config->trigger);
    }

    if (self->count == self->config->count) {
        u32 j;

        for (j = 0; j < self->config->count; ++j) {
            if (self->entries[j].active)
                break;
        }

        if (j == self->config->count) {
            self->done = 1;
            setTriggerFlag__12stTriggerMngFP13stTriggerData(
                g_stTriggerMng, self->config->trigger);
        }
    }

    self->time += fn_8004E94C(g_GameGlobal);
}
