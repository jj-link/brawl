#pragma force_active on
typedef unsigned int u32;
typedef int s32;

class EcMgr {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    u32 pad[3];
    u32 unk10;
    u32 unk14;
    u32 unk18;
};

class Alloc {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(void* p, s32 a, s32 b);
};

extern EcMgr* lbl_805A0EC8;
extern Alloc* lbl_805A0EB8;

extern "C" {
u32* dtor_803115AC(u32* arg0, s32 arg1) {
    if (arg0 != 0) {
        u32 temp = *arg0;
        EcMgr* mgr = lbl_805A0EC8;
        mgr->unk10 = temp;
        if (temp == mgr->unk18) {
            mgr->v4();
        }
        if (arg1 > 0) {
            lbl_805A0EB8->v5(arg0, 8, 0x15);
        }
    }
    return arg0;
}
}
