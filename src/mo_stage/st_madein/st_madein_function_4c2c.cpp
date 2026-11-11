#pragma force_active on

struct Vec3f {
    float x, y, z;
};

extern "C" {
extern const float lbl_65_rodata_0[];
extern void* g_ecMgr;
extern void* g_GameGlobal;
extern const char lbl_65_data_4AC;

unsigned int isEndEntity__8grMadeinFv(void*);
void startEntity__8grMadeinFv(void*);
void endEntity__8grMadeinFv(void*);
void setMotion__8grMadeinFUl(void*, unsigned long);
long getPhase__13grTenganEventCFv(const void*);
void setPhase__13grTenganEventFl(void*, long);
bool isEvent__13grTenganEventCFv(const void*);
void end__13grTenganEventFv(void*);
void* getGround__5StageFi(void*, int);
float randf__Fv();
unsigned int randi__Fl(long);
void playSeBasic__7stMeleeF5SndIDf(void*, int, float);
unsigned long setEffect__5ecMgrF4EfID(void*, int);
void setParent__5ecMgrFUlPQ34nw4r3g3d6ScnMdlPCcb(void*, unsigned long, void*, const char*, bool);
void setPos__9grGimmickFP5Vec3f(void*, Vec3f*);
void cmReqQuake__FiP5Vec3f(int, Vec3f*);
void cmRemoveQuake__Fi(int);
unsigned int fn_27_2793BC(void*, float);
unsigned int fn_8004E96C(void*);
}

struct Stage {
    char pad0[0x284];
    char e1[0xAC];
    char pad1[0x3DC - 0x330];
    char e2[0xAC];
    char pad2[0x948 - 0x488];
    unsigned char unk948;
    char pad3[3];
    int unk94C;
    int unk950;
    unsigned char unk954;
    unsigned char unk955;
    unsigned char unk956;
    unsigned char unk957;
    char pad4[0x9F4 - 0x958];
    unsigned char unk9F4;
    unsigned char unk9F5;
};

extern "C" int fn_65_4C2C(Stage* self) {
    const float* rd = lbl_65_rodata_0;
    unsigned long effect;
    Vec3f pos;
    Vec3f vec;

    switch (getPhase__13grTenganEventCFv(&self->e1)) {
    case 0:
        if (isEndEntity__8grMadeinFv(getGround__5StageFi(self, 0x39)) == 1) {
            self->unk957 = 1;
            self->unk956 = 1;
            self->unk955 = 1;
            self->unk954 = 1;
            if (self->unk948 == 1) {
                setMotion__8grMadeinFUl(getGround__5StageFi(self, 0x39), 0);
            } else {
                setMotion__8grMadeinFUl(getGround__5StageFi(self, 0x39), 1);
            }
            startEntity__8grMadeinFv(getGround__5StageFi(self, 0x39));
            setPhase__13grTenganEventFl(&self->e1, 1);

            unsigned int count = randi__Fl(2);
            if (count >= 1)
                count = 1;
            self->unk94C = count;
            self->unk950 = 0;
            self->unk9F5 = 0;
            self->unk9F4 = 1;
        }
        break;

    case 1:
        self->unk9F5 = 0;
        if (isEndEntity__8grMadeinFv(getGround__5StageFi(self, 0x39)) == 1) {
            if (self->unk950 == 0) {
                if (self->unk94C != 0) {
                    unsigned int r = randi__Fl(0x1F);
                    if (r >= 0x1E)
                        r = 0x1E;
                    self->unk950 = r + 0xF;

                    if (rd[4] - rd[27] * randf__Fv() < rd[0]) {
                        setMotion__8grMadeinFUl(getGround__5StageFi(self, 0x39), 6);
                    } else {
                        setMotion__8grMadeinFUl(getGround__5StageFi(self, 0x39), 7);
                    }
                    self->unk9F5 = 1;
                    startEntity__8grMadeinFv(getGround__5StageFi(self, 0x39));
                    playSeBasic__7stMeleeF5SndIDf(self, 0x1CB2, rd[0]);
                    setPhase__13grTenganEventFl(&self->e1, 1);
                    self->unk94C -= 1;
                } else {
                    setPhase__13grTenganEventFl(&self->e1, 2);
                }
            } else {
                self->unk950 -= 1;
            }
        }
        break;

    case 2:
        if (isEndEntity__8grMadeinFv(getGround__5StageFi(self, 0x39)) == 1) {
            setMotion__8grMadeinFUl(getGround__5StageFi(self, 0x39), 2);
            startEntity__8grMadeinFv(getGround__5StageFi(self, 0x39));
            self->unk9F5 = 1;
            setPhase__13grTenganEventFl(&self->e1,
                getPhase__13grTenganEventCFv(&self->e1) + 1);
            playSeBasic__7stMeleeF5SndIDf(self, 0x1CB3, rd[0]);
        }
        break;

    case 3:
        self->unk9F5 = 0;
        if (fn_27_2793BC(getGround__5StageFi(self, 0x39), rd[3]) == 1) {
            self->unk9F4 = 0;
            effect = setEffect__5ecMgrF4EfID(g_ecMgr, 0x4D0001);
            setParent__5ecMgrFUlPQ34nw4r3g3d6ScnMdlPCcb(g_ecMgr, effect,
                *(void**)(*(void**)((char*)getGround__5StageFi(self, 0x39) + 0x44)),
                &lbl_65_data_4AC, false);
            setPhase__13grTenganEventFl(&self->e1,
                getPhase__13grTenganEventCFv(&self->e1) + 1);

            vec.x = rd[0];
            vec.y = rd[0];
            vec.z = rd[0];
            cmReqQuake__FiP5Vec3f(5, &vec);
            playSeBasic__7stMeleeF5SndIDf(self, 0x1CB4, rd[0]);
        }
        break;

    case 4:
        if (isEndEntity__8grMadeinFv(getGround__5StageFi(self, 0x39)) == 1) {
            if (fn_8004E96C(g_GameGlobal) == 1) {
                pos.x = rd[0x11C / 4];
                pos.y = rd[0x24 / 4];
                pos.z = rd[0];
                setPos__9grGimmickFP5Vec3f(getGround__5StageFi(self, 0x72), &pos);
                startEntity__8grMadeinFv(getGround__5StageFi(self, 0x72));
                setMotion__8grMadeinFUl(getGround__5StageFi(self, 0x39), 3);
                startEntity__8grMadeinFv(getGround__5StageFi(self, 0x39));
                setPhase__13grTenganEventFl(&self->e1,
                    getPhase__13grTenganEventCFv(&self->e1) + 1);
            }
        }
        break;

    case 5:
        if (fn_8004E96C(g_GameGlobal) == 1) {
            endEntity__8grMadeinFv(getGround__5StageFi(self, 0x72));
            for (int i = 0; i < 4; i++) {
                unsigned char* g = (unsigned char*)getGround__5StageFi(self, 0x72);
                unsigned char* p = *(unsigned char**)(g + 0x15C) + i;
                if (p[0x1C] != 0)
                    (&self->unk954)[i] = 0;
            }
            setPhase__13grTenganEventFl(&self->e1,
                getPhase__13grTenganEventCFv(&self->e1) + 1);
        }
        break;

    case 6:
        if (isEndEntity__8grMadeinFv(getGround__5StageFi(self, 0x39)) == 1) {
            cmRemoveQuake__Fi(1);
            if (isEvent__13grTenganEventCFv(&self->e2) == 0) {
                end__13grTenganEventFv(&self->e1);
            }
        }
        break;
    }

    return 0;
}
