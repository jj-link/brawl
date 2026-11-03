#include <snd/snd_system.h>
#pragma force_active on

extern "C" void fn_800C09FC(void* self, int v);
extern "C" int fn_800B5854(void* p, int a, int b, int c, int d);

class VObj {
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
    virtual void target(void* a, void* b);
};

extern "C" void fn_800C15AC(void* self) {
    char* s = (char*)self;
    *(int*)(s + 0x3cc) = g_sndSystem->getBGMId();
    fn_800C09FC(self, *(int*)(s + 0x220));
    {
        VObj* o = *(VObj**)(s + 0x58);
        o->target(*(void**)((char*)o + 0xe4), *(void**)(s + 0x54));
    }
    fn_800B5854(*(void**)(s + 0x40), 0, 1, 1, 0);
}
