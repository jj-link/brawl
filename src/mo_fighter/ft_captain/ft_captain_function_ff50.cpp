#pragma force_active on
struct gfSceneRoot {
    unsigned char padding[0x465];
    unsigned char flags;
};

extern "C" {
extern gfSceneRoot* g_gfSceneRoot;

void fn_8000D07C(void*, int);
void fn_8000D67C(void*);

void fn_100_FF50() {
    fn_8000D07C(g_gfSceneRoot, 0);
    fn_8000D67C(g_gfSceneRoot);
    g_gfSceneRoot->flags |= 8;
}
}
