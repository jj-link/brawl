#pragma force_active on
typedef unsigned long u32;

struct AnimPart {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void rate(float);
};

struct ModelAnimation {
    char pad[12];
    AnimPart* chr;
    void* unk10;
    AnimPart* tex;

    void setTexRate(float f) {
        tex->rate(f);
    }
};

struct GroundBase {
    char pad0[0x3c];
};

struct GroundVirtual : GroundBase {
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
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void change(u32, u32);
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void finish();
};

struct Ground : GroundVirtual {
    u32 resFile;
    char pad44[4];
    ModelAnimation** animations;
    char pad4c[0x70];
    char* data;
    char padc0[0x9c];
    float value;
    char pad160[0x44];
    char* copiedData;
};

extern "C" {
    void fn_40_24E58(Ground*);
    u32 GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(const void*);
    void OSReport(const char*, ...);
    extern char lbl_40_data_15418[];
    void changeTexSrtAnim__9grGimmickFUlUl(Ground*, u32, u32);
    void changeVisibleAnim__9grGimmickFUlUl(Ground*, u32, u32);
    void setUpdateRate__16gfModelAnimationFf(ModelAnimation*, float);
    extern float lbl_40_rodata_81C;
    extern float lbl_40_rodata_820;
    extern float lbl_27_data_547E0;
    extern void* g_stTriggerMng;
    void createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(
        void*, int, void*);

    void fn_40_3B618(Ground* self) {
        fn_40_24E58(self);
        self->copiedData = self->data;
        OSReport(
            lbl_40_data_15418,
            GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(&self->resFile));

        self->change(0, 0);
        changeTexSrtAnim__9grGimmickFUlUl(self, 0, 0);
        changeVisibleAnim__9grGimmickFUlUl(self, 0, 0);
        setUpdateRate__16gfModelAnimationFf(
            self->animations[0], lbl_40_rodata_81C);

        self->change(1, 1);
        changeTexSrtAnim__9grGimmickFUlUl(self, 1, 1);

        AnimPart* p = self->animations[1]->chr;
        p->rate(lbl_40_rodata_81C);
        self->animations[1]->setTexRate(lbl_27_data_547E0);

        self->value = lbl_40_rodata_820;
        for (int i = 0; i < 40; i++) {
            createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(
                g_stTriggerMng, 40, self->copiedData + 0x90 + i * 4);
        }
        self->finish();
    }
}
