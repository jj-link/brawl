#pragma force_active on

typedef unsigned long u32;
typedef unsigned char u8;

struct WindData {
    char pad[0x34];
    float strength;
    char pad38[8];
    float strengths[15];
};

struct Counts {
    u32 pad;
    u32 count;
};

struct Container {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual WindData* get(u32);
    u32 pad;
    Counts* counts;
};

struct GameData {
    char pad[0x5fd];
    u8 level;
    char pad5fe[0x4916 - 0x5fe];
    u8 adjustment;
};

struct GameGlobal {
    char pad[0x30];
    GameData* data;
};

extern "C" {
extern GameGlobal* g_GameGlobal;

Container* searchContainer__20stDataMultiContainerFUlUl(void*, u32, u32);
void createGimmickWind2__15stCommonGimmickFP17grGimmickWindData(
    void*, WindData*, int);

void fn_40_BB2C(void* self, u32 kind, void* multi) {
    Container* container;
    u32 n = 0;

    while ((container = searchContainer__20stDataMultiContainerFUlUl(
                multi, kind, n++)) != 0) {
        for (u32 i = 0; i < container->counts->count; i++) {
            WindData* data = container->get(i);
            GameData* game = g_GameGlobal->data;
            int level = game->level;
            int minimum = level - 5;
            int index = level - game->adjustment;

            if (index < minimum)
                index = minimum;
            if (index < 0)
                index = 0;
            if (index > 14)
                index = 14;

            data->strength = data->strengths[(u8)index];
            createGimmickWind2__15stCommonGimmickFP17grGimmickWindData(
                self, data, 0);
        }
    }
}
}
