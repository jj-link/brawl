#include <sr/sr_common.h>
#include <internal/mem.h>
#pragma force_active on

extern "C" {
void fn_63_2B6C(void*, const char*);
extern char lbl_63_data_5D48[];
extern const float lbl_63_rodata_1E0;
}
struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void processDefault();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void processPreMapCorrection();
    virtual void slot5();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void slot12();
    virtual void processEffect();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42(int);
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78(const char*);
};
extern "C" Object_vptr_3c* fn_63_14728(int model, const char* node, const char* name) {
    Object_vptr_3c* p = (Object_vptr_3c*)operator new(0x1f8, Heaps::StageInstance);
    if (p) {
        fn_63_2B6C(p, name);
        *(void**)((char*)p + 0x3c) = lbl_63_data_5D48;
        *(int*)((char*)p + 0x1f0) = 0;
        *(int*)((char*)p + 0x1f4) = 0;
        *(int*)((char*)p + 0x1ec) = 0;
        *(void**)((char*)p + 0x1f0) = (char*)p + 0x1f0;
        *(void**)((char*)p + 0x1f4) = (char*)p + 0x1f0;
        *(int*)((char*)p + 0x174) = 0;
        *(int*)((char*)p + 0x1e4) = 0;
        *(unsigned char*)((char*)p + 0x1e8) = 1;
        memset((char*)p + 0x180, 0, 4);
        memset((char*)p + 0x188, 0, 0x5c);
        *(int*)((char*)p + 0x178) = 0;
        *(int*)((char*)p + 0x17c) = 0;
        *(float*)((char*)p + 0x1e0) = lbl_63_rodata_1E0;
    }
    if (p) {
        p->slot42(model);
        p->slot78(node);
    }
    return p;
}
