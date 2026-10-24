#pragma force_active on
struct Vec2 { float x; float y; };
struct Vec3 { float x; float y; float z; };
struct Blk { void* w[9]; };

extern "C" {
void startup__9grGimmickFP9gfArchiveUlUl(void* self, void* archive, unsigned long a, unsigned long b);
void unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(void* anim, void* mdl);
void makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(void* self, unsigned long a, int b);
void setCalcuCallbackRoot__9grGimmickFUl(void* self, unsigned long a);
void createAttachMotionPath__9grGimmickFP23grGimmickMotionPathInfoP13stTriggerDataPCc(void* self, void* info, void* trig, const char* name);
void getPos__9grGimmickFv(Vec3* out, void* self);
int fn_27_2724A4(void* a, Vec2* b, unsigned char c, int d, float e);
void fn_27_27255C(void* a, int b, int c, int d);
int createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(void* mng, int kind, void* data);
void fn_40_2E564(void* a, void* b, int c, void* d, int e, int f);
}
extern char lbl_40_data_88E8[];
extern Blk lbl_40_data_88F8;
extern char* g_GameGlobal;
extern void* g_stTriggerMng;

extern "C" void fn_40_29A24(char* self, void* archive, unsigned long a, unsigned long b) {
    startup__9grGimmickFP9gfArchiveUlUl(self, archive, a, b);
    char* base = *(char**)(self + 0xBC);
    *(char**)(self + 0x164) = base;
    unsigned char* gg = *(unsigned char**)(g_GameGlobal + 0x30);
    *(float*)base = *(float*)(base + (gg[0x5FD] << 2) + 8);
    char* anim = *(char**)(self + 0x48);
    if (anim != 0) {
        unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(*(void**)anim, *(void**)(*(char**)(self + 0x44)));
    }
    makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(self, 1, 0xF);
    setCalcuCallbackRoot__9grGimmickFUl(self, 3);
    Blk blk = lbl_40_data_88F8;
    blk.w[0] = archive;
    blk.w[1] = *(void**)(self + 0x164);
    blk.w[3] = *(char**)(self + 0x164) + 0x48;
    blk.w[4] = *(char**)(self + 0x164) + 0x120;
    blk.w[5] = *(char**)(self + 0x164) + 0x198;
    blk.w[6] = *(char**)(self + 0x164) + 0x6C;
    blk.w[7] = *(char**)(self + 0x164) + 0x15C;
    blk.w[8] = *(char**)(self + 0x164) + 0x1BC;
    createAttachMotionPath__9grGimmickFP23grGimmickMotionPathInfoP13stTriggerDataPCc(self, &blk, *(char**)(self + 0x164) + 0x1E4, lbl_40_data_88E8);
    Vec3 pos;
    getPos__9grGimmickFv(&pos, self);
    Vec2 v8;
    v8.x = pos.x;
    v8.y = pos.y;
    char* q = *(char**)(self + 0x164);
    float fv = *(float*)(q + 0x24C);
    unsigned char cv = *(unsigned char*)(q + 0x248);
    int r = fn_27_2724A4(self + 0x14C, &v8, cv, 0, fv);
    *(int*)(self + 0x168) = r;
    fn_27_27255C(self + 0x14C, 1, 0, r);
    char* t = *(char**)(self + 0x164);
    if (*(unsigned short*)(t + 0x1E4) != 0 && (t[0x1E6] & 1)) {
        fn_27_27255C(self + 0x14C, 0, 0, *(int*)(self + 0x168));
    }
    int tr = createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(g_stTriggerMng, 0, *(char**)(self + 0x164) + 0x1E4);
    char* p4 = self;
    if (self != 0) {
        p4 = self + 0x154;
    }
    fn_40_2E564(self + 0x154, p4, tr, *(char**)(self + 0x164) + 0x1E4, 1, 0);
}
