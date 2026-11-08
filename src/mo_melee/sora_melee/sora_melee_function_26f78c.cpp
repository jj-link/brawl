#pragma force_active on

class gfArchive;
struct Vec3f {
    float x, y, z;
};
struct soAreaData {
    unsigned char shape, group;
    unsigned short flags;
    int a, b, node;
    float x, y, z, w;
};
template<class T>
struct soSet {
    char pad[8];
};
struct ykAreaData {
    char pad[12];
};
struct MotionInfo {
    void* v[9];
};
struct Data {
    char pad0[0x20];
    float x, y, z, w;
};

struct grYakumono {
    void setAreaGimmick(soAreaData*, soSet<soAreaData>*, ykAreaData*, bool);
};

extern "C" {
void startup__10grYakumonoFP9gfArchiveUlQ211gfSceneRoot9LayerType(void*, gfArchive*, unsigned long, int);
void unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(void*, void*);
void makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(void*, unsigned long, int);
void setCalcuCallbackRoot__9grGimmickFUl(void*, unsigned long);
void createAttachMotionPath__9grGimmickFP23grGimmickMotionPathInfoP13stTriggerDataPCc(void*, MotionInfo*, void*, const char*);
void updateG3dProcCalcWorld__6GroundFv(void*);
void getNodePosition__6GroundFP5Vec3fUlUl(void*, Vec3f*, unsigned long, unsigned long);
void setPos__9grGimmickFP5Vec3f(void*, Vec3f*);
void* createTrigger__12stTriggerMngFQ27Gimmick8AreaKindi(void*, int, int);
void setObserveYakumono__9stTriggerFP8Yakumono(void*, void*);
void createIsValidTrigger__9grGimmickFP13stTriggerData(void*, void*);
extern void* g_stTriggerMng;
extern char lbl_27_data_572E0[];
extern MotionInfo lbl_27_rodata_43EC;
}

struct GroundBase {
    char pad[0x3c];
};

class Ground : public GroundBase {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
    virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34();
    virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44();
    virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49();
    virtual void s50(); virtual void s51(); virtual void s52(); virtual void s53(); virtual void s54();
    virtual void s55(); virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59();
    virtual void s60(); virtual void s61(); virtual void s62(); virtual void s63(); virtual void s64();
    virtual void s65(); virtual void s66(); virtual void s67(); virtual void s68(); virtual void s69();
    virtual void s70(); virtual void s71(); virtual void s72(); virtual void s73(); virtual void s74();
    virtual void s75(); virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79();
    virtual void s80();
    virtual void* getGimmickData();
};

struct grGimmickLadder : public Ground {
    char pad40[4];
    void** unk44;
    void** unk48;
    char pad4c[0x100];
    void* unk14C;
    void* unk150;
    soAreaData area;
    soSet<soAreaData> areaSet;
    ykAreaData areaData;

    void startup(gfArchive* arch, unsigned long a, unsigned long b);
};

void grGimmickLadder::startup(gfArchive* arch, unsigned long a, unsigned long b) {
    startup__10grYakumonoFP9gfArchiveUlQ211gfSceneRoot9LayerType(this, arch, a, (int)b);
    this->unk150 = this->getGimmickData();
    if (this->unk48 != 0) {
        unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(*this->unk48, *this->unk44);
    }
    makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(this, 1, 0xF);
    setCalcuCallbackRoot__9grGimmickFUl(this, 1);

    MotionInfo info = lbl_27_rodata_43EC;
    info.v[0] = arch;
    info.v[1] = this->unk150;
    createAttachMotionPath__9grGimmickFP23grGimmickMotionPathInfoP13stTriggerDataPCc(
        this, &info, (char*)this->unk150 + 0x58, lbl_27_data_572E0);
    updateG3dProcCalcWorld__6GroundFv(this);

    Vec3f pos;
    getNodePosition__6GroundFP5Vec3fUlUl(this, &pos, 0, 0);
    setPos__9grGimmickFP5Vec3f(this, &pos);

    this->area.shape = 0;
    this->area.group = 0x16;
    this->area.a = 0;
    this->area.b = 0;
    this->area.flags = 0;
    this->area.node = 0;
    this->area.x = ((Data*)this->unk150)->x;
    this->area.y = ((Data*)this->unk150)->y;
    this->area.z = ((Data*)this->unk150)->z;
    this->area.w = ((Data*)this->unk150)->w;

    ((grYakumono*)this)->setAreaGimmick(&this->area, &this->areaSet, &this->areaData, false);
    setObserveYakumono__9stTriggerFP8Yakumono(
        createTrigger__12stTriggerMngFQ27Gimmick8AreaKindi(g_stTriggerMng, 0x25, -1),
        this->unk14C);
    createIsValidTrigger__9grGimmickFP13stTriggerData(this, (char*)this->unk150 + 0x54);
}
