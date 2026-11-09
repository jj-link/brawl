#pragma force_active on

extern "C" {
extern const char lbl_66_data_0[];
extern const float lbl_66_rodata_0[];
}

#define S(n) virtual void n();
struct Ground {
    char pad[0x3c];
    S(v0) S(v1) S(v2) S(v3) S(v4) S(v5)
    S(v6) S(v7) S(v8) S(v9) S(v10) S(v11)
    S(v12) S(v13) S(v14) S(v15) S(v16) S(v17)
    S(v18) S(v19) S(v20) S(v21) S(v22) S(v23)
    S(v24) S(v25) S(v26) S(v27) S(v28) S(v29)
    S(v30) S(v31) S(v32) S(v33) S(v34) S(v35)
    S(v36)
    virtual void v37(int, int, int);
    S(v38)
    virtual void v39(int);
    S(v40) S(v41) S(v42) S(v43) S(v44) S(v45)
    S(v46) S(v47) S(v48) S(v49) S(v50) S(v51)
    S(v52) S(v53) S(v54) S(v55) S(v56) S(v57)
    S(v58) S(v59) S(v60) S(v61) S(v62) S(v63)
    S(v64) S(v65) S(v66) S(v67) S(v68) S(v69)
    S(v70) S(v71) S(v72) S(v73) S(v74) S(v75)
    S(v76) S(v77) S(v78) S(v79) S(v80) S(v81)
    S(v82) S(v83) S(v84) S(v85) S(v86) S(v87)
    S(v88) S(v89) S(v90) S(v91) S(v92) S(v93)
    S(v94) S(v95) S(v96) S(v97) S(v98) S(v99)
    S(v100) S(v101) S(v102) S(v103) S(v104) S(v105)
    S(v106) S(v107) S(v108) S(v109) S(v110) S(v111)
    S(v112) S(v113) S(v114) S(v115)
    virtual void v116(float);
    S(v117) S(v118) S(v119)
    virtual void v120(int);
    virtual void v121(void*);
    virtual void v122(int);
};
#undef S

struct Stage {
    char pad0[0x9c];
    int f9c;
    char padA0[0x100];
    int f1a0;
    char pad1A4[0x58];
    char f1fc[3][0xc];
    char pad238[0x58];
    int f278;
};

extern "C" {
Ground* fn_66_58A4(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_66_90C(Stage* self, int kind) {
    const float* rodata = lbl_66_rodata_0;
    Ground* ground;
    float val;
    int index;
    const char* data = lbl_66_data_0;

    switch (kind) {
    case 5:
        ground = fn_66_58A4(1, data + 0x7c, data + 0x88);
        val = rodata[1];
        index = 0;
        break;
    case 6:
        ground = fn_66_58A4(2, data + 0x98, data + 0xa4);
        val = rodata[2];
        index = 1;
        break;
    case 7:
        ground = fn_66_58A4(3, data + 0xb8, data + 0xc4);
        val = rodata[3];
        index = 2;
        break;
    default:
        ground = 0;
        break;
    }

    if (ground) {
        addGround__5StageFP6Ground(self, ground);
        ground->v37(self->f1a0, 0, 0);
        ground->v39(self->f9c);
        ground->v120(index);
        ground->v116(val);
        ground->v121(self->f1fc[index]);
        ground->v122(self->f278);
    }
}
}
