#include <types.h>
#pragma force_active on

class gfArchive;

extern "C" u32 getFrameCount__16gfModelAnimationFd(void* anim);
extern "C" u32 getNodeIndex__6GroundFUlPCc(void* self, u32 sceneModelIndex, const char* nodeName);
extern "C" void makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(void* self, u32 arg1, int heapType);
extern "C" void setCalcuCallbackRoot__9grGimmickFUl(void* self, u32 arg1);
extern "C" void startGimmickSE__9grGimmickFUl(void* self, u32 index);
extern "C" void startGimmickEffect__9grGimmickFUl(void* self, u32 index);
extern "C" void startup__6GroundFP9gfArchiveUlUl(void* self, gfArchive* data, u32 unk1, u32 unk2);

struct grGimmickMotionPath_base {
    char pad[0x3c];
};

class grGimmickMotionPath : public grGimmickMotionPath_base {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual void unused53();
    virtual void unused54();
    virtual void unused55();
    virtual void unused56();
    virtual void unused57();
    virtual void unused58();
    virtual void unused59();
    virtual void unused60();
    virtual void unused61();
    virtual void unused62();
    virtual void unused63();
    virtual void unused64();
    virtual void unused65();
    virtual void unused66();
    virtual void unused67();
    virtual void unused68();
    virtual void unused69();
    virtual void unused70();
    virtual void unused71();
    virtual void unused72();
    virtual void unused73();
    virtual void unused74();
    virtual void unused75();
    virtual void unused76();
    virtual void unused77();
    virtual void unused78();
    virtual void unused79();
    virtual void unused80();
    virtual void* getGimmickData();   // 0x14c
    virtual void unused82();
    virtual void unused83();
    virtual void unused84();
    virtual void unused85();
    virtual void unused86();
    virtual void unused87();
    virtual void unused88();
    virtual void unused89();
    virtual void unused90();
    virtual void unused91();
    virtual void setFrameModelAnim(); // 0x178

    char _40[0x8];
    void** m_48;
    char _4c[0x6c - 0x4c];
    u8 m_6c;
    char _6d[0xa8 - 0x6d];
    void* m_a8;
    char _ac[4];
    void* m_b0;
    char _b4[0x160 - 0xb4];
    u32 m_frameCount;
    void* m_motionPathData;
    char _168[0x10];
    u32 m_178;
    u32 m_nodeIndex;
    char m_nodeName[32];

    void startup(gfArchive* data, u32 unk1, u32 unk2);
};

void grGimmickMotionPath::startup(gfArchive* data, u32 unk1, u32 unk2) {
    m_motionPathData = getGimmickData();
    startup__6GroundFP9gfArchiveUlUl(this, data, unk1, unk2);
    m_frameCount = getFrameCount__16gfModelAnimationFd(m_48[0]);
    m_6c |= 2;
    makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(this, 1, 0xf);
    setCalcuCallbackRoot__9grGimmickFUl(this, 0);
    m_178 = 0;
    m_nodeIndex = getNodeIndex__6GroundFUlPCc(this, 0, m_nodeName);
    setFrameModelAnim();
    if (m_a8 != NULL) {
        for (int i = 0; i < 3; i++) {
            startGimmickSE__9grGimmickFUl(this, i);
        }
    }
    if (m_b0 != NULL) {
        for (int i = 0; i < 3; i++) {
            startGimmickEffect__9grGimmickFUl(this, i);
        }
    }
}
