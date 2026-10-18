#pragma force_active on
typedef unsigned char u8;

struct Model {
    char pad[12];
    void* mdl;
};

struct TitleScene {
    char pad[0x48];
    char resFile[8];
    Model* mdl1;
    Model* mdl2;
    char pad2[4];
    void* anm;
    char pad3[0x10];
    u8 ready;
};

extern "C" {
extern void* g_gfSceneRoot;

void add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(void*, int, void*);
void fn_801971D0(void*, void*);
void fn_8000D6DC(void*, void*);
void* GetResAnmScn__Q34nw4r3g3d7ResFileFi(void*, int);

void fn_24_20D4(TitleScene* s) {
    if (s->ready == 1)
        return;

    s->anm = GetResAnmScn__Q34nw4r3g3d7ResFileFi((char*)s + 0x48, 0);
    void* tmp = s->anm;
    fn_801971D0(&s->anm, &tmp);
    fn_8000D6DC(g_gfSceneRoot, &s->anm);
    add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, 8, s->mdl1->mdl);
    add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, 8, s->mdl2->mdl);
    s->ready = 1;
}
}
