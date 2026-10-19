#include <types.h>
#include <snd/snd_system.h>
#pragma force_active on

struct FtInner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int, int);
};

struct FtOuter {
    char pad[0x64];
    FtInner* inner;
};

extern "C" {
void fn_80076274(sndSystem*, int);
extern sndSystem* g_sndSystem;

void fn_92_F258(void* unused, void* fighter) {
    fn_80076274(g_sndSystem, 0x1B4B);
    FtOuter* obj = *(FtOuter**)((char*)fighter + 0xD8);
    obj->inner->v5(-1, 0x10000042);
}
}
