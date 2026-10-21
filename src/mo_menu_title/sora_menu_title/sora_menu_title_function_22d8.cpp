#pragma force_active on
struct Holder {
    char _00[0x0c];
    void* _0c;
};

struct Obj {
    char _00[0x50];
    Holder* _50;
    Holder* _54;
    Holder* _58;
    char _5c[0x70 - 0x5c];
    unsigned char _70;
    unsigned char _71;
};

extern "C" {
extern void* g_gfSceneRoot;
void fn_8000D7B8(void*);
void fn_8019733C(void*);
void remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(void*, void*);
}

extern "C" void fn_24_22D8(Obj* self) {
    if (self->_70 != 0) {
        fn_8000D7B8(g_gfSceneRoot);
        fn_8019733C(self->_5c);
        remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, self->_50->_0c);
        remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, self->_54->_0c);
        self->_70 = 0;
    }
    if (self->_71 != 0) {
        fn_8000D7B8(g_gfSceneRoot);
        fn_8019733C(self->_5c);
        remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, self->_58->_0c);
        self->_71 = 0;
    }
}
