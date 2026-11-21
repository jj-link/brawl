#pragma force_active on
#include <gf/gf_3d_scene.h>

struct Outer;
extern "C" void fn_8010DE64(Outer*);

class SceneObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11(void* a, void* b);
};

struct Inner {
    int pad0;
    void* p4;
};

struct Outer {
    int pad0;
    Inner* p4;
};

extern "C" void fn_8010ED14(Outer* self) {
    SceneObj* obj = *(SceneObj**)&g_gfSceneRoot->_104[1000];
    if (self->p4->p4 != obj) {
        fn_8010DE64(self);
        obj->v11(*(void**)((char*)obj + 0xE4), self->p4);
    }
}
