#pragma force_active on
extern "C" void update__9grGimmickFf(void* self, float deltaFrame);

struct GimmickPad {
    char pad0[0x3c];
};

class GimmickBase : public GimmickPad {
public:
    virtual void v0(float f);
    virtual void v1(float f);
    virtual void v2(float f);
    virtual void v3(float f);
    virtual void v4(float f);
    virtual void v5(float f);
    virtual void v6(float f);
    virtual void v7(float f);
    virtual void v8(float f);
    virtual void v9(float f);
    virtual void v10(float f);
    virtual void v11(float f);
    virtual void v12(float f);
    virtual void v13(float f);
    virtual void v14(float f);
    virtual void v15(float f);
    virtual void v16(float f);
    virtual void v17(float f);
    virtual void v18(float f);
    virtual void v19(float f);
    virtual void v20(float f);
    virtual void v21(float f);
    virtual void v22(float f);
    virtual void v23(float f);
    virtual void v24(float f);
    virtual void v25(float f);
    virtual void v26(float f);
    virtual void v27(float f);
    virtual void v28(float f);
    virtual void v29(float f);
    virtual void v30(float f);
    virtual void v31(float f);
    virtual void v32(float f);
    virtual void v33(float f);
    virtual void v34(float f);
    virtual void v35(float f);
    virtual void v36(float f);
    virtual void v37(float f);
    virtual void v38(float f);
    virtual void v39(float f);
    virtual void v40(float f);
    virtual void v41(float f);
    virtual void v42(float f);
    virtual void v43(float f);
    virtual void v44(float f);
    virtual void v45(float f);
    virtual void v46(float f);
    virtual void v47(float f);
    virtual void v48(float f);
    virtual void v49(float f);
    virtual void v50(float f);
    virtual void v51(float f);
    virtual void v52(float f);
    virtual void v53(float f);
    virtual void v54(float f);
    virtual void v55(float f);
    virtual void v56(float f);
    virtual void v57(float f);
    virtual void v58(float f);
    virtual void v59(float f);
    virtual void v60(float f);
    virtual void v61(float f);
    virtual void v62(float f);
    virtual void v63(float f);
    virtual void v64(float f);
    virtual void v65(float f);
    virtual void v66(float f);
    virtual void v67(float f);
    virtual void v68(float f);
    virtual void v69(float f);
    virtual void v70(float f);
    virtual void v71(float f);
    virtual void v72(float f);
    virtual void v73(float f);
    virtual void v74(float f);
    virtual void v75(float f);
    virtual void v76(float f);
    virtual void v77(float f);
    virtual void v78(float f);
    virtual void v79(float f);
    virtual void v80(float f);
    virtual void v81(float f);
    virtual void v82(float f);
    virtual void v83(float f);
    virtual void v84(float f);
    virtual void v85(float f);
    virtual void v86(float f);
    virtual void v87(float f);
    virtual void v88(float f);
    virtual void v89(float f);
    virtual void v90(float f);
    virtual void v91(float f);
    virtual void v92(float f);
    virtual void v93(float f);
    virtual void v94(float f);
    virtual void v95(float f);
    virtual void v96(float f);
    virtual void v97(float f);
    virtual void v98(float f);
    virtual void v99(float f);
    virtual void v100(float f);
    virtual void v101(float f);
    virtual void v102(float f);
    virtual void v103(float f);
    virtual void v104(float f);
    virtual void v105(float f);
    virtual void v106(float f);
    virtual void v107(float f);
    virtual void v108(float f);
    virtual void v109(float f);
    virtual void v110(float f);
    virtual void v111(float f);
    virtual void v112(float f);
    virtual void v113(float f);
    virtual void v114(float f);
    virtual void v115(float f);
    virtual void v116(float f);
};

class GimmickObj : public GimmickBase {
public:
    char pad1[0xc8 - 0x40];
    unsigned char flag;
};

extern "C" void fn_54_E7D0(void* self, float deltaFrame) {
    GimmickObj* obj = (GimmickObj*)self;
    update__9grGimmickFf(self, deltaFrame);
    if (obj->flag != 0) {
        obj->v114(deltaFrame);
        obj->v113(deltaFrame);
    }
}
