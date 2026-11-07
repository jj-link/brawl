#pragma force_active on

typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
void testStageParamInit__5StageFP9gfArchivei(void*, void*, int);
void testStageDataInit__5StageFP9gfArchiveii(void*, void*, int, int);
void createCollision__5StageFP9gfArchiveiP6Ground(void*, void*, int, void*);
void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, u16);
void createStagePositions__5StageFPQ34nw4r3g3d7ResFile(void*, void*);
void createStagePositions__5StageFv(void*);
void loadStageAttrParam__5StageFP9gfArchivei(void*, void*, int);
void registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(void*, void*, unsigned long);
void initPosPokeTrainer__5StageFii(void*, int, int);
extern char lbl_48_data_0[];
}

struct GameGlobal {
    char pad[8];
    u8* modeMelee;
};
extern GameGlobal* g_GameGlobal;

struct Stage_base {
    char pad[0x3C];
};

class Stage : public Stage_base {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(void*, int, const char*, void*, void*);
    virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
    virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87();
    virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91();
    virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95();
    virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
    virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103();
    virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107();
    virtual void v108(); virtual void v109(); virtual void v110(); virtual void v111();
    virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115();
    virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119();
    virtual void v120(); virtual void v121(); virtual void v122(); virtual void v123();
    virtual void v124(); virtual void v125(); virtual void v126(); virtual void v127();
    virtual void v128(); virtual void v129(); virtual void v130(); virtual void v131();
    virtual void v132();
    virtual void v133(int); virtual void v134(int); virtual void v135(int); virtual void v136(int);

    char padToGround[0x7C];
    char* ground;
    char padToArchive[0xE0];
    void* archive;
    char pad1A4[0x6C];
    char f210[0xC];
    char f21C[0xC];
    char pad228[0x9C];
    u8 kind;
    char pad2C5[0x4A];
    u8 flag30F;
};

extern "C" void fn_48_30C(Stage* self) {
    const char* names = lbl_48_data_0;
    testStageDataInit__5StageFP9gfArchiveii(self, self->archive, 0x14, 0x28);
    u8* mode = g_GameGlobal->modeMelee;
    if (mode == 0) return;
    switch (mode[0x1c]) {
    case 0: self->kind = 0; break;
    case 1: self->kind = 1; break;
    default: self->kind = 0; break;
    }
    testStageParamInit__5StageFP9gfArchivei(self, self->archive, 0xA);
    self->v134(0);
    self->v133(1);
    createCollision__5StageFP9gfArchiveiP6Ground(self, self->archive, 2, 0);
    self->v135(2);
    self->v136(3);
    self->v47();
    void* data = getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 2, 0x64, (u16)0xFFFE);
    if (data) {
        void* posData = data;
        createStagePositions__5StageFPQ34nw4r3g3d7ResFile(self, &posData);
    } else {
        createStagePositions__5StageFv(self);
    }
    self->v123();
    initPosPokeTrainer__5StageFii(self, 4, 0);
    switch (self->kind) {
    case 0:
        self->v24(self->archive, 0x65, names + 0xC, self->ground, self->f210);
        self->v24(self->archive, 0x66, names + 0x1C, self->ground + 0x18, self->f210);
        self->v24(self->archive, 0x67, names + 0x2C, self->ground + 0x30, self->f21C);
        self->v24(self->archive, 0x68, names + 0x3C, self->ground + 0x48, self->f21C);
        break;
    case 1:
        self->v24(self->archive, 0x65, names + 0xC, self->ground, self->f210);
        self->v24(self->archive, 0x66, names + 0x1C, self->ground + 0x18, self->f21C);
        self->v24(self->archive, 0x67, names + 0x2C, self->ground + 0x30, self->f21C);
        self->v24(self->archive, 0x68, names + 0x3C, self->ground + 0x48, self->f210);
        break;
    }
    loadStageAttrParam__5StageFP9gfArchivei(self, self->archive, 0x1E);
    registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(self,
        getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 5, 0, (u16)0xFFFE), 0);
    mode = g_GameGlobal->modeMelee;
    if (mode != 0) {
        if ((((u32)mode[8] >> 2) & 0x3f) == 7) {
            if ((u32)mode[0x10] == 8) {
                self->flag30F = 1;
            }
        }
    }
}
