#pragma force_active on
typedef unsigned char u8;

extern "C" {
void fn_8000D7B8(void*);
void fn_8019733C(void*);
void remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(void* root, void* mdl);
extern void* g_gfSceneRoot;
}

struct SubObj {
    u8 _00[0x0c];
    void* _0c;
};

struct Obj {
    u8 _00[0x58];
    SubObj* _58;
    u8 _5c[0x71 - 0x5c];
    u8 _71;
};

extern "C" void fn_24_2270(Obj* self) {
    if (self->_71 != 0) {
        fn_8000D7B8(g_gfSceneRoot);
        fn_8019733C(&self->_5c);
        remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, self->_58->_0c);
        self->_71 = 0;
    }
}
