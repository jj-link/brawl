#pragma force_active on

struct GrBase { char pad[0x3c]; };
class Ground : public GrBase {
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual float getMotionFrame(unsigned long);
    char pad40[4];
    void** model;
};

struct StageT {
    char pad0[0x828];
    int tengo;
    char pad1[0x6b4];
    int unkEE0;
};

extern "C" {
extern void* g_ecMgr;
extern const float lbl_60_rodata_0;
extern const float lbl_60_rodata_B0;
extern const char lbl_60_data_438[];

long getPhase__13grTenganEventCFv(const void* self);
void setPhase__13grTenganEventFl(void* self, long phase);
Ground* getGround__5StageFi(void* self, int index);
int isEndEntity__8grMadeinFv(void* self);
void startEntity__8grMadeinFv(void* self);
void endEntity__8grMadeinFv(void* self);
void setMotion__8grMadeinFUl(void* self, unsigned long motion);
void setDrawPrio__5ecMgrFi(void* self, int prio);
unsigned long setEffect__5ecMgrF4EfID(void* self, int id);
void setParent__5ecMgrFUlPQ34nw4r3g3d6ScnMdlPCcb(void* self, unsigned long effect, void* mdl, const char* name, bool b);
int playSeBasic__7stMeleeF5SndIDf(void* self, int sndID, float pan);
void fn_27_279250(void* self, int arg);

int fn_60_3E48(StageT* self) {
    switch (getPhase__13grTenganEventCFv(&self->tengo)) {
    case 0:
        if (isEndEntity__8grMadeinFv(getGround__5StageFi(self, 3))) {
            setMotion__8grMadeinFUl(getGround__5StageFi(self, 3), 5);
            startEntity__8grMadeinFv(getGround__5StageFi(self, 3));
            setPhase__13grTenganEventFl(&self->tengo, 1);
            self->unkEE0 = -1;
        }
        break;
    case 1:
        if (self->unkEE0 == -1) {
            Ground* g3 = getGround__5StageFi(self, 3);
            if (g3->getMotionFrame(0) >= lbl_60_rodata_B0) {
                self->unkEE0 = playSeBasic__7stMeleeF5SndIDf(self, 0x1C4F, lbl_60_rodata_0);
            }
        }
        if (isEndEntity__8grMadeinFv(getGround__5StageFi(self, 3))) {
            setDrawPrio__5ecMgrFi(g_ecMgr, 1);
            unsigned long effect = setEffect__5ecMgrF4EfID(g_ecMgr, 0x460005);
            setDrawPrio__5ecMgrFi(g_ecMgr, -1);
            setParent__5ecMgrFUlPQ34nw4r3g3d6ScnMdlPCcb(g_ecMgr, effect, *getGround__5StageFi(self, 3)->model, lbl_60_data_438, false);
            setMotion__8grMadeinFUl(getGround__5StageFi(self, 3), 6);
            fn_27_279250(getGround__5StageFi(self, 3), 2);
            startEntity__8grMadeinFv(getGround__5StageFi(self, 0x1a));
            setPhase__13grTenganEventFl(&self->tengo, 2);
            playSeBasic__7stMeleeF5SndIDf(self, 0x1C50, lbl_60_rodata_0);
        }
        break;
    case 2:
        if (isEndEntity__8grMadeinFv(getGround__5StageFi(self, 3))) {
            setMotion__8grMadeinFUl(getGround__5StageFi(self, 3), 7);
            startEntity__8grMadeinFv(getGround__5StageFi(self, 3));
            endEntity__8grMadeinFv(getGround__5StageFi(self, 0x1a));
            setPhase__13grTenganEventFl(&self->tengo, 3);
        }
        break;
    case 3:
        if (isEndEntity__8grMadeinFv(getGround__5StageFi(self, 3))) {
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;
}
}