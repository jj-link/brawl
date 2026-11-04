#pragma force_active on
typedef float f32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct Vec3f { f32 x, y, z; };
struct gfArchive;
struct stTriggerMng;
struct stTriggerData;

struct GObj_base { char pad[0x3c]; };

class GObj : public GObj_base {
public:
    virtual void s0();   virtual void s1();   virtual void s2();   virtual void s3();
    virtual void s4();   virtual void s5();   virtual void s6();   virtual void s7();
    virtual void s8();   virtual void s9();   virtual void s10();  virtual void s11();
    virtual void s12();  virtual void s13();  virtual void s14();  virtual void s15();
    virtual void s16();  virtual void s17();  virtual void s18();  virtual void s19();
    virtual void s20();  virtual void s21();  virtual void s22();  virtual void s23();
    virtual void s24();  virtual void s25();  virtual void s26();  virtual void s27();
    virtual void s28();  virtual void s29();  virtual void s30();  virtual void s31();
    virtual void s32();  virtual void s33();  virtual void s34();  virtual void s35();
    virtual void s36();  virtual void s37();  virtual void s38();  virtual void s39();
    virtual void s40();  virtual void s41();  virtual void s42();  virtual void s43();
    virtual void s44();  virtual void s45();  virtual void s46();  virtual void s47();
    virtual void s48();  virtual void s49();  virtual void s50();  virtual void s51();
    virtual void s52();  virtual void s53();  virtual void s54();  virtual void s55();
    virtual void s56();  virtual void s57();  virtual void s58();  virtual void s59();
    virtual void s60();  virtual void s61();  virtual void s62();  virtual void s63();
    virtual void s64();  virtual void s65();  virtual void s66();  virtual void s67();
    virtual void s68();  virtual void s69();  virtual void s70();
    virtual void updateG3dProcCalcWorld();  // declared slot 71
    virtual void s72();  virtual void s73();  virtual void s74();  virtual void s75();
    virtual void updateCallback(u32);       // declared slot 76
};

struct GObjData {
    char pad0[0x150];
    u8 unk150;
    char pad151[3];
    u32 unk154;
};

struct GimmickData {
    char pad0[0x40];
    u8 unk40;
    char pad41[3];
    f32 unk44;
    u16 unk48;
};

struct ListNode {
    char pad0[4];
    ListNode* next;
    GObj* obj;
};

struct grGimmick {
    char pad0[0x3C];
    void* vtbl;
    char pad40[4];
    void** unk44;
    char pad48[0x74];
    void* unkBC;
    char padC0[0x8C];
    char pad14C[4];
    u8 unk150;
    char pad151[3];
    void* unk154;
    char pad158[4];
    ListNode* unk15C;
    u32 unk160;
    GimmickData* unk164;
};

extern "C" void startup__9grGimmickFP9gfArchiveUlUl(grGimmick* self, gfArchive* arg, u32 a, u32 b);
extern "C" void fn_40_221A0(grGimmick* self, gfArchive* arg);
extern "C" void fn_40_227A0(grGimmick* self);
extern "C" void setPos__9grGimmickFP5Vec3f(void* self, Vec3f* p);
extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFi(void* self, s32 idx);
extern "C" void* fn_27_2724A4(void* self, f32* p, u8 a, s32 b, f32 c, f32 d);
extern "C" void createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(stTriggerMng* self, s32 kind, stTriggerData* data);
extern stTriggerMng* g_stTriggerMng;

extern "C" void fn_40_2237C(grGimmick* self, gfArchive* arg1, u32 arg2, u32 arg3) {
    u32 sp8;
    f32 sp10[2];
    Vec3f pos;
    GObj* obj;
    u32 n;
    u32 i;
    f32 f31;
    u8 r27;

    startup__9grGimmickFP9gfArchiveUlUl(self, arg1, arg2, arg3);
    self->unk164 = (GimmickData*)self->unkBC;
    fn_40_221A0(self, arg1);
    i = 0;
    sp8 = *(u32*)((char*)*self->unk44 + 0xE8);
    n = self->unk160;
    self->unk15C = (ListNode*)self->unk154;
    while (i < n) {
        obj = self->unk15C->obj;
        GObjData* od = (GObjData*)obj;
        void* res = GetResNode__Q34nw4r3g3d6ResMdlCFi(&sp8, od->unk150);
        pos.x = ((f32*)res)[0x38 / 4];
        pos.y = ((f32*)res)[0x3C / 4];
        pos.z = ((f32*)res)[0x40 / 4];
        f31 = self->unk164->unk44;
        r27 = self->unk164->unk40;
        setPos__9grGimmickFP5Vec3f(obj, &pos);
        obj->updateCallback(0);
        obj->updateG3dProcCalcWorld();
        sp10[0] = pos.x;
        sp10[1] = pos.y;
        od->unk154 = (u32)fn_27_2724A4(&self->pad14C, sp10, r27, 1, f31, pos.x);
        i += 1;
        self->unk15C = self->unk15C->next;
    }
    if (*(u16*)((char*)self->unk164 + 0x48) != 0) {
        createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(g_stTriggerMng, 0, (stTriggerData*)((char*)self->unk164 + 0x48));
    }
    fn_40_227A0(self);
}
