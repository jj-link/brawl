#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;
typedef int s32;

class GameGlobal {
public:
    void setSlowRate(u8 rate);
};

enum EfID { EfID_Dummy = 0 };

class ecMgr {
public:
    u32 setEffect(EfID id);
};

extern GameGlobal* g_GameGlobal;
extern ecMgr* g_ecMgr;

struct FnObj {
    char pad0[0x48];
    s32 unk48;
    s32 unk4C;
    char pad1[0xc];
    float unk5C;
};

extern "C" {
void fn_27_25C330(FnObj* self) {
    g_GameGlobal->setSlowRate((u8)self->unk5C);
    g_ecMgr->setEffect((EfID)0x1030010);
    self->unk4C = 0;
    self->unk48 = 6;
}
}
