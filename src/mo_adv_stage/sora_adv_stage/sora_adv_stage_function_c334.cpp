#pragma force_active on

typedef unsigned long u32;
typedef unsigned char u8;

struct grGimmickLadderData {
    float value;
    char pad[0x58];
    float values[15];
};

struct stCommonGimmick {
    char pad[0x1a0];
    void* archive;
};

struct Counts {
    u32 pad;
    u32 count;
};

struct Container {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual grGimmickLadderData* get(u32);
    u32 pad;
    Counts* counts;
};

struct GameData {
    char pad0[0x5fd];
    u8 value;
    char pad1[0x4916 - 0x5fe];
    u8 offset;
};

struct GameGlobal {
    char pad[0x30];
    GameData* data;
};

extern "C" {
extern GameGlobal* g_GameGlobal;

Container* searchContainer__20stDataMultiContainerFUlUl(void*, u32, u32);
void createGimmickLadder__15stCommonGimmickFP19grGimmickLadderDataP9gfArchive(
    stCommonGimmick*, grGimmickLadderData*, void*);

void fn_40_C334(stCommonGimmick* self, u32 kind, void* multi) {
    Container* container;
    u32 n = 0;

    while ((container = searchContainer__20stDataMultiContainerFUlUl(
                multi, kind, n++)) != 0) {
        for (u32 i = 0; i < container->counts->count; i++) {
            grGimmickLadderData* data = container->get(i);
            GameData* game = g_GameGlobal->data;
            u8 level = game->value;
            int minimum = level - 5;
            int value = level - game->offset;

            if (value < minimum)
                value = minimum;
            if (value < 0)
                value = 0;
            if (value > 14)
                value = 14;

            data->value = data->values[(u8)value];
            createGimmickLadder__15stCommonGimmickFP19grGimmickLadderDataP9gfArchive(
                self, data, self->archive);
        }
    }
}
}
