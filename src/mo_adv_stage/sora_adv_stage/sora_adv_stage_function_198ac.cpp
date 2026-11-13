#pragma force_active on

extern "C" {
    void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
    void* fn_40_19CA8(void* obj, int param, const char* name);
    int fn_40_19E3C(void* a, int b);
}

struct grYakumono_base { char pad[0x3c]; };

class grYakumono : public grYakumono_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void fn_40_199DC();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_40_197FC();
    virtual void fn_40_198A8();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual unsigned int getModelCount();

    int m_40;
    int* m_44;
    char pad48[0x150 - 0x48];
    void* m_150[4];
};

extern "C" int fn_40_198AC(grYakumono* self) {
    unsigned int count;
    char* pp;
    unsigned int off;
    unsigned int i;
    unsigned int j;
    void* p;

    p = __nw__FUlQ25Heaps8HeapType(0x54, 0xF);
    if (p != 0) {
        p = fn_40_19CA8(p, 0, "enkei1");
    }
    self->m_150[0] = p;

    p = __nw__FUlQ25Heaps8HeapType(0x54, 0xF);
    if (p != 0) {
        p = fn_40_19CA8(p, 1, "enkei2");
    }
    self->m_150[1] = p;

    p = __nw__FUlQ25Heaps8HeapType(0x54, 0xF);
    if (p != 0) {
        p = fn_40_19CA8(p, 2, "enkei3");
    }
    self->m_150[2] = p;

    p = __nw__FUlQ25Heaps8HeapType(0x54, 0xF);
    if (p != 0) {
        p = fn_40_19CA8(p, 3, "enkei4");
    }
    self->m_150[3] = p;

    count = self->getModelCount();
    pp = (char*)self;
    for (i = 0; i < 4; i++) {
        j = 0;
        off = 0;
        while (j < count) {
            if (fn_40_19E3C(*(void**)(pp + 0x150), *(int*)((char*)self->m_44 + off)) != 0) {
                break;
            }
            off += 4;
            j++;
        }
        pp += 4;
    }
    return 1;
}