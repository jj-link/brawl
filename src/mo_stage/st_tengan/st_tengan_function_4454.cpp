#pragma force_active on
extern "C" {
extern void* g_ecMgr;
extern const float lbl_60_rodata_0;
int getPhase__13grTenganEventCFv(const void*);
void setPhase__13grTenganEventFl(void*, long);
void* getGround__5StageFi(void*, int);
int isEndEntity__8grMadeinFv(void*);
void startEntity__8grMadeinFv(void*);
void endEntity__8grMadeinFv(void*);
void setMotion__8grMadeinFUl(void*, unsigned long);
unsigned long setEffect__5ecMgrF4EfID(void*, int);
void endEffect__5ecMgrFUl(void*, unsigned long);
void end__13grTenganEventFv(void*);
void playSeBasic__7stMeleeF5SndIDf(void*, int, float);
}

struct StageT {
    char pad0[0xCDC];
    char tengan[0x1D8];
    unsigned long effect;
};

extern "C" int fn_60_4454(StageT* self) {
    switch (getPhase__13grTenganEventCFv(self->tengan)) {
    case 0:
        if (isEndEntity__8grMadeinFv(getGround__5StageFi(self, 0x13))) {
            self->effect = setEffect__5ecMgrF4EfID(g_ecMgr, 0x460007);
            setMotion__8grMadeinFUl(getGround__5StageFi(self, 0x13), 5);
            startEntity__8grMadeinFv(getGround__5StageFi(self, 0x13));
            setMotion__8grMadeinFUl(getGround__5StageFi(self, 0x20), 0);
            startEntity__8grMadeinFv(getGround__5StageFi(self, 0x20));
            endEntity__8grMadeinFv(getGround__5StageFi(self, 1));
            setPhase__13grTenganEventFl(self->tengan,
                getPhase__13grTenganEventCFv(self->tengan) + 1);
            playSeBasic__7stMeleeF5SndIDf(self, 0x1C65, lbl_60_rodata_0);
        }
        break;
    case 1:
        if (isEndEntity__8grMadeinFv(getGround__5StageFi(self, 0x20))) {
            setMotion__8grMadeinFUl(getGround__5StageFi(self, 0x20), 1);
            startEntity__8grMadeinFv(getGround__5StageFi(self, 0x20));
            setPhase__13grTenganEventFl(self->tengan,
                getPhase__13grTenganEventCFv(self->tengan) + 1);
        }
        break;
    case 2:
        if (isEndEntity__8grMadeinFv(getGround__5StageFi(self, 0x20))) {
            setMotion__8grMadeinFUl(getGround__5StageFi(self, 0x20), 2);
            startEntity__8grMadeinFv(getGround__5StageFi(self, 0x20));
            setPhase__13grTenganEventFl(self->tengan,
                getPhase__13grTenganEventCFv(self->tengan) + 1);
        }
        break;
    case 3:
        if (isEndEntity__8grMadeinFv(getGround__5StageFi(self, 0x20))) {
            endEntity__8grMadeinFv(getGround__5StageFi(self, 0x20));
            startEntity__8grMadeinFv(getGround__5StageFi(self, 1));
            end__13grTenganEventFv(self->tengan);
            endEffect__5ecMgrFUl(g_ecMgr, self->effect);
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;
}
