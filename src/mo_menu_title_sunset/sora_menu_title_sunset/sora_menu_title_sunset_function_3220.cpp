#pragma force_active on
typedef unsigned char u8;

struct Model {
    char pad[12];
    void* mdl;
};

struct State {
    char p0[0xe4];
    Model* base[4];
    Model* models[35];
    char gap[8];
    int count;
    char p18c[0x218 - 0x18c];
    int ids[35];
    char rest[0x144e - 0x2a4];
    u8 ready;
    u8 pad;
    void* anm;

    inline bool has(int id) {
        for (int i = 0; i < count; ++i) {
            if (ids[i] == id)
                return true;
        }
        return false;
    }
};

struct Record {
    char pad[0x28];
    unsigned char flag : 1;
    unsigned char other : 7;
};

extern "C" {
extern void* g_gfSceneRoot;
extern void* g_GameGlobal;

void add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(
    void*, int, void*);
void fn_25_3470(State*);
Record* getGlobalRecordMenuDatap__10GameGlobalFv(void*);
void* GetResAnmScn__Q34nw4r3g3d7ResFileFi(void*, int);
void fn_801971D0(void*, void*);
void fn_8000D2E0(void*, void*, int);

void fn_25_3220(State* s) {
    if (s->ready == 1)
        return;

    add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(
        g_gfSceneRoot, 0, s->base[0]->mdl);
    add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(
        g_gfSceneRoot, 0, s->base[1]->mdl);
    add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(
        g_gfSceneRoot, 0, s->base[2]->mdl);
    add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(
        g_gfSceneRoot, 0, s->base[3]->mdl);

    int i;
    State* cursor = s;
    for (i = 0; i < 35; ++i, cursor = (State*)((char*)cursor + 4)) {
        if (s->has(i) == true) {
            add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(
                g_gfSceneRoot, 3, cursor->models[0]->mdl);
        }
    }

    fn_25_3470(s);

    if (getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal)->flag == 0) {
        s->anm = GetResAnmScn__Q34nw4r3g3d7ResFileFi((char*)s + 0x48, 1);
    } else {
        s->anm = GetResAnmScn__Q34nw4r3g3d7ResFileFi((char*)s + 0x48, 0);
    }

    void* tmp = s->anm;
    fn_801971D0(&s->anm, &tmp);
    fn_8000D2E0(g_gfSceneRoot, &s->anm, 43);
    s->ready = 1;
}
}
