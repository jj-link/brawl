#pragma force_active on
typedef int s32;
typedef float f32;

struct MuObject {
    void changeAnimN(const char* name);
};

enum SndID { SND_NONE = 0 };

struct sndSystem {
    void playSE(SndID id, s32 a, s32 b, s32 c, s32 d);
};

struct InnerObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual f32 getVal();
};

extern sndSystem* g_sndSystem;
extern "C" s32 fn_800B63B8(MuObject* obj);
extern const char lbl_26_data_1A8[];

struct Self {
    char pad0[0x6cc];
    MuObject* obj;
    char pad1[0x1368 - 0x6d0];
    s32 state;
};

extern "C" s32 fn_26_11A0(Self* self) {
    MuObject* obj = self->obj;
    if (fn_800B63B8(obj) != 0) {
        obj->changeAnimN(lbl_26_data_1A8);
        self->state = 4;
    } else {
        char* a = *(char**)((char*)obj + 0x14);
        InnerObj* b = *(InnerObj**)(a + 0xc);
        s32 v = (s32)b->getVal();
        if (v == 0xaa) {
            g_sndSystem->playSE((SndID)0x1ee6, -1, 0, 0, -1);
        }
        if (v == 0xbe) {
            g_sndSystem->playSE((SndID)0x1ee6, -1, 0, 0, -1);
        }
        if (v == 0xd1) {
            g_sndSystem->playSE((SndID)0x1ee6, -1, 0, 0, -1);
        }
    }
    return self->state;
}
