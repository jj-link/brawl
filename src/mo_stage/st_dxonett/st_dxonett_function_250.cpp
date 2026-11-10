#pragma force_active on

typedef unsigned short u16;

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
extern char lbl_78_data_C[];
extern void* g_cmAIController;
extern float lbl_78_rodata_4;
}

struct Stage_base {
    char pad[0x3C];
};

class Stage : public Stage_base {
public:
    virtual void v2();   // 0x8
    virtual void v3();   // 0xc
    virtual void v4();   // 0x10
    virtual void v5();   // 0x14
    virtual void v6();   // 0x18
    virtual void v7();   // 0x1c
    virtual void v8();   // 0x20
    virtual void v9();   // 0x24
    virtual void v10();  // 0x28
    virtual void v11();  // 0x2c
    virtual void v12();  // 0x30
    virtual void v13();  // 0x34
    virtual void v14();  // 0x38
    virtual void v15();  // 0x3c
    virtual void v16();  // 0x40
    virtual void v17();  // 0x44
    virtual void v18();  // 0x48
    virtual void v19();  // 0x4c
    virtual void v20();  // 0x50
    virtual void v21();  // 0x54
    virtual void v22();  // 0x58
    virtual void v23();  // 0x5c
    virtual void v24();  // 0x60
    virtual void v25();  // 0x64
    virtual void v26(void*, int, const char*, void*, int); // 0x68
    virtual void v27();  // 0x6c
    virtual void v28();  // 0x70
    virtual void v29();  // 0x74
    virtual void v30();  // 0x78
    virtual void v31();  // 0x7c
    virtual void v32();  // 0x80
    virtual void v33();  // 0x84
    virtual void v34();  // 0x88
    virtual void v35();  // 0x8c
    virtual void v36();  // 0x90
    virtual void v37();  // 0x94
    virtual void v38();  // 0x98
    virtual void v39();  // 0x9c
    virtual void v40();  // 0xa0
    virtual void v41();  // 0xa4
    virtual void v42();  // 0xa8
    virtual void v43();  // 0xac
    virtual void v44();  // 0xb0
    virtual void v45();  // 0xb4
    virtual void v46();  // 0xb8
    virtual void v47();  // 0xbc
    virtual void v48();  // 0xc0
    virtual void v49();  // 0xc4
    virtual void v50();  // 0xc8
    virtual void v51();  // 0xcc
    virtual void v52();  // 0xd0
    virtual void v53();  // 0xd4
    virtual void v54();  // 0xd8
    virtual void v55();  // 0xdc
    virtual void v56();  // 0xe0
    virtual void v57();  // 0xe4
    virtual void v58();  // 0xe8
    virtual void v59();  // 0xec
    virtual void v60();  // 0xf0
    virtual void v61();  // 0xf4
    virtual void v62();  // 0xf8
    virtual void v63();  // 0xfc
    virtual void v64();  // 0x100
    virtual void v65();  // 0x104
    virtual void v66();  // 0x108
    virtual void v67();  // 0x10c
    virtual void v68();  // 0x110
    virtual void v69();  // 0x114
    virtual void v70();  // 0x118
    virtual void v71();  // 0x11c
    virtual void v72();  // 0x120
    virtual void v73();  // 0x124
    virtual void v74();  // 0x128
    virtual void v75();  // 0x12c
    virtual void v76();  // 0x130
    virtual void v77();  // 0x134
    virtual void v78();  // 0x138
    virtual void v79();  // 0x13c
    virtual void v80();  // 0x140
    virtual void v81();  // 0x144
    virtual void v82();  // 0x148
    virtual void v83();  // 0x14c
    virtual void v84();  // 0x150
    virtual void v85();  // 0x154
    virtual void v86();  // 0x158
    virtual void v87();  // 0x15c
    virtual void v88();  // 0x160
    virtual void v89();  // 0x164
    virtual void v90();  // 0x168
    virtual void v91();  // 0x16c
    virtual void v92();  // 0x170
    virtual void v93();  // 0x174
    virtual void v94();  // 0x178
    virtual void v95();  // 0x17c
    virtual void v96();  // 0x180
    virtual void v97();  // 0x184
    virtual void v98();  // 0x188
    virtual void v99();  // 0x18c
    virtual void v100(); // 0x190
    virtual void v101(); // 0x194
    virtual void v102(); // 0x198
    virtual void v103(); // 0x19c
    virtual void v104(); // 0x1a0
    virtual void v105(); // 0x1a4
    virtual void v106(); // 0x1a8
    virtual void v107(); // 0x1ac
    virtual void v108(); // 0x1b0
    virtual void v109(); // 0x1b4
    virtual void v110(); // 0x1b8
    virtual void v111(); // 0x1bc
    virtual void v112(); // 0x1c0
    virtual void v113(); // 0x1c4
    virtual void v114(); // 0x1c8
    virtual void v115(); // 0x1cc
    virtual void v116(); // 0x1d0
    virtual void v117(); // 0x1d4
    virtual void v118(); // 0x1d8
    virtual void v119(); // 0x1dc
    virtual void v120(); // 0x1e0
    virtual void v121(); // 0x1e4
    virtual void v122(); // 0x1e8
    virtual void v123(); // 0x1ec
    virtual void v124(); // 0x1f0
    virtual void v125(); // 0x1f4
    virtual void v126(); // 0x1f8
    virtual void v127(); // 0x1fc
    virtual void v128(); // 0x200
    virtual void v129(); // 0x204
    virtual void v130(); // 0x208
    virtual void v131(); // 0x20c
    virtual void v132(); // 0x210
    virtual void v133(); // 0x214
    virtual void v134(); // 0x218
    virtual void v135(int); // 0x21c
    virtual void v136(int); // 0x220
    virtual void v137(int); // 0x224
    virtual void v138(int); // 0x228
    virtual void v139(int); // 0x22c
    virtual void v140(int); // 0x230
    virtual void v141(int); // 0x234
    virtual void v142();    // 0x238

    char padToGround[0x7C];
    void* ground;
    char padToArchive[0xE0];
    void* archive;
};

extern "C" void fn_78_250(Stage* self) {
    testStageParamInit__5StageFP9gfArchivei(self, self->archive, 0xA);
    testStageDataInit__5StageFP9gfArchiveii(self, self->archive, 0x14, 0x4C);

    self->v135(0);
    self->v136(1);
    self->v137(2);
    self->v137(3);
    self->v138(4);
    self->v138(5);

    createCollision__5StageFP9gfArchiveiP6Ground(self, self->archive, 2, 0);

    self->v139(6);
    self->v139(7);
    self->v139(8);
    self->v139(9);
    self->v140(0xA);
    self->v141(0xB);
    self->v142();
    self->v49();

    void* data = getData__9gfArchiveF11ARCNodeTypeiUs(
        self->archive, 2, 0x64, (u16)0xFFFE);
    if (data) {
        void* posData = data;
        createStagePositions__5StageFPQ34nw4r3g3d7ResFile(self, &posData);
    } else {
        createStagePositions__5StageFv(self);
    }

    self->v125();
    loadStageAttrParam__5StageFP9gfArchivei(self, self->archive, 0x1E);

    void* animData = getData__9gfArchiveF11ARCNodeTypeiUs(
        self->archive, 5, 0, (u16)0xFFFE);
    registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(self, animData, 0);
    initPosPokeTrainer__5StageFii(self, 1, 0);

    self->v26(self->archive, 0x65, lbl_78_data_C, self->ground, 0);

    unsigned char* ai = (unsigned char*)g_cmAIController;
    float f = lbl_78_rodata_4;
    ai[0x94] |= 4;
    *(float*)(ai + 0x184) = f;
}
