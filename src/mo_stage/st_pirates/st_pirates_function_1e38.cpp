#pragma force_active on
struct WindDataBig {
    char pad[0x38];
    float f38;
    float f3c;
    float f40;
    float f44;
    char pad48[0x6c - 0x48];
    float f6c;
    float f70;
    char pad74[0x80 - 0x74];
    float f80;
    char pad84[0x88 - 0x84];
    float f88;
    float f8c;
};

struct WindData2nd {
    char pad[0x34];
    float f34;
    float f38;
    float f3c;
    float f40;
    float f44;
    unsigned long f48;
};

struct Stage_base { char pad[0x3c]; };

class Stage : public Stage_base {
public:
    virtual void v0();   virtual void v1();   virtual void v2();   virtual void v3();
    virtual void v4();   virtual void v5();   virtual void v6();   virtual void v7();
    virtual void v8();   virtual void v9();   virtual void v10();  virtual void v11();
    virtual void v12();  virtual void v13();  virtual void v14();  virtual void v15();
    virtual void v16();  virtual void v17();  virtual void v18();  virtual void v19();
    virtual void v20();  virtual void v21();  virtual void v22();  virtual void v23();
    virtual void v24();  virtual void v25();  virtual void v26();  virtual void v27();
    virtual void v28();  virtual void v29();  virtual void v30();  virtual void v31();
    virtual void v32();  virtual void v33();  virtual void v34();  virtual void v35();
    virtual void v36();  virtual void v37();  virtual void v38();  virtual void v39();
    virtual void v40();  virtual void v41();  virtual void v42();  virtual void v43();
    virtual void v44();  virtual void v45();  virtual void v46();  virtual void v47();
    virtual void v48();  virtual void v49();  virtual void v50();  virtual void v51();
    virtual void v52();  virtual void v53();  virtual void v54();  virtual void v55();
    virtual void v56();  virtual void v57();  virtual void v58();  virtual void v59();
    virtual void v60();  virtual void v61();  virtual void v62();  virtual void v63();
    virtual void v64();  virtual void v65();  virtual void v66();  virtual void v67();
    virtual void v68();  virtual void v69();  virtual void v70();  virtual void v71();
    virtual void v72();  virtual void v73();  virtual void v74();  virtual void v75();
    virtual void v76();  virtual void v77();  virtual void v78();  virtual void v79();
    virtual void v80();  virtual void v81();  virtual void v82();  virtual void v83();
    virtual void v84();  virtual void v85();  virtual void v86();  virtual void v87();
    virtual void v88();  virtual void v89();  virtual void v90();  virtual void v91();
    virtual void v92();  virtual void v93();  virtual void v94();  virtual void v95();
    virtual void v96();  virtual void v97();  virtual void v98();  virtual void v99();
    virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103();
    virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107();
    virtual void v108(); virtual void v109(); virtual void v110(); virtual void v111();
    virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115();
    virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119();
    virtual void v120(); virtual void v121(); virtual void v122(); virtual void v123();
    virtual void v124(); virtual void v125(); virtual void v126(); virtual void v127();
    virtual void v128(); virtual void v129(); virtual void v130(); virtual void v131();
    virtual void v132(); virtual void v133(); virtual void v134(); virtual void v135();
    virtual void v136(); virtual void v137(); virtual void v138(); virtual void v139();
    virtual void v140(); virtual void v141(); virtual void v142(); virtual void v143();
    virtual void v144(); virtual void v145(); virtual void v146(); virtual void v147();
    virtual void v148(); virtual void v149(); virtual void v150(); virtual void v151();
    virtual void fn_52_25E4(float);
    virtual void fn_52_2818(float);
    virtual void fn_52_28B8(float);
    virtual void fn_52_2984(float);
    virtual void v156(); virtual void v157(); virtual void v158(); virtual void v159();
    virtual void v160(); virtual void v161();
    virtual void fn_52_31EC();
    virtual void fn_52_32D8();
    virtual void fn_52_32F4();

    char pad_40[0x9c - 0x40];
    WindDataBig* d9c;
    char pad_a0[0x1c4 - 0xa0];
    void* d1c4;
    WindData2nd* d1c8;
    char pad_1cc[0x1e0 - 0x1cc];
    unsigned char d1e0;
    unsigned char d1e1;
    char pad_1e2[0x55d - 0x1e2];
    unsigned char d55d;
    float d560;
    float d564;
    unsigned char d568;
    unsigned char d569;
    unsigned char d56a;
    unsigned char d56b;
    unsigned char d56c;
    char pad_56d[0x5e0 - 0x56d];
    float d5e0;
    char pad_5e4[0x5f1 - 0x5e4];
    unsigned char d5f1;
    char pad_5f2[0x5fc - 0x5f2];
    void* d5fc;
    void* d600;
    float d604;
    unsigned char d608;
    unsigned char d609;
    unsigned char d60a;
    unsigned char d60b;
};

extern "C" {
extern const float lbl_52_rodata_0[];
float randf__Fv();
void setAreaSleep__9stTriggerFb(void* trigger, bool b);
void setWindParam__9stTriggerFP20grGimmickWindData2ndl(void* trigger, void* wnd, long p);
void fn_27_233C70(void* a, void* b);

void fn_52_1E38(Stage* self, float dt) {
    const float* d = lbl_52_rodata_0;
    WindDataBig* w = self->d9c;
    if (w != 0) {
        self->d560 -= dt;
        if (self->d560 < d[0]) self->d560 = d[0];
        self->d564 -= dt;
        if (self->d564 < d[0]) self->d564 = d[0];
        switch (self->d55d) {
        case 0:
            if (self->d56a == 1) {
                self->d560 = w->f38 + (w->f3c - w->f38) * randf__Fv();
                self->d56a = 0;
            } else {
                self->d560 = w->f40 + (w->f44 - w->f40) * randf__Fv();
            }
            if (self->d608 == 1)
                self->d560 = d[0];
            self->d609 = 0;
            self->d60a = 0;
            self->d60b = 7;
            self->d55d = 1;
            return;
        case 1:
            if (d[0] == self->d560) {
                self->fn_52_25E4(dt);
                return;
            }
            break;
        case 3:
            self->fn_52_2818(dt);
            return;
        case 4:
        case 5:
        case 6:
            if (self->d1e0 == 1) {
                self->fn_52_28B8(dt);
                return;
            }
            break;
        case 7:
            if (self->d1e0 == 1) {
                self->fn_52_31EC();
                self->d568 = 5;
                self->d55d = 8;
                return;
            }
            break;
        case 8:
            if (self->d1e0 == 1) {
                self->d1e1 = 3;
                self->d564 = d[12];
                self->d568 = 6;
                self->d55d = 9;
                return;
            }
            break;
        case 9: {
            float v = self->d564;
            if (v < d[13]) {
                self->d1c8->f34 = d[14];
                self->d1c8->f38 = d[15];
                self->d1c8->f3c = d[16];
                self->d1c8->f40 = d[17];
                self->d1c8->f48 = 0x28;
                setWindParam__9stTriggerFP20grGimmickWindData2ndl(self->d1c4, self->d1c8, 0);
                setAreaSleep__9stTriggerFb(self->d1c4, 0);
                self->d609 = 0;
                self->d60a = 0;
            } else if (v < d[18]) {
                self->d1c8->f34 = d[17];
                self->d1c8->f38 = d[0];
                self->d1c8->f3c = d[19];
                self->d1c8->f40 = d[20];
                self->d1c8->f48 = 0x50;
                setWindParam__9stTriggerFP20grGimmickWindData2ndl(self->d1c4, self->d1c8, 0);
                setAreaSleep__9stTriggerFb(self->d1c4, 0);
            } else if (v < d[21]) {
                setAreaSleep__9stTriggerFb(self->d1c4, 1);
            } else if (v < d[22]) {
                self->d1c8->f34 = d[17];
                self->d1c8->f38 = d[0];
                self->d1c8->f3c = d[19];
                self->d1c8->f40 = d[20];
                self->d1c8->f48 = 0x50;
                setWindParam__9stTriggerFP20grGimmickWindData2ndl(self->d1c4, self->d1c8, 0);
                setAreaSleep__9stTriggerFb(self->d1c4, 0);
                self->d609 = 7;
                self->d60a = 7;
            }
            if (self->d1e0 == 1) {
                int c = self->d1e1 - 1;
                self->d1e1 = (unsigned char)c;
                if ((unsigned char)c != 0) return;
                if (self->d608 == 1) {
                    self->d55d = 7;
                    return;
                }
                self->d569 = self->d568;
                self->fn_52_2818(dt);
                self->fn_52_28B8(dt);
                return;
            }
            break;
        }
        case 10:
            if (self->d1e0 == 1) {
                self->fn_52_32D8();
                self->d560 = w->f6c + (w->f70 - w->f6c) * randf__Fv();
                self->d568 = 7;
                self->d5e0 = d[23];
                self->d1e1 = 4;
                self->d564 = d[23];
                self->d55d = 0xb;
                return;
            }
            break;
        case 11:
            if (self->d1e0 == 1) {
                int c = self->d1e1 - 1;
                self->d1e1 = (unsigned char)c;
                if ((unsigned char)c != 0) return;
                self->d569 = self->d568;
                self->fn_52_2818(dt);
                self->fn_52_28B8(dt);
                return;
            } else {
                self->fn_52_2984(dt);
                return;
            }
            break;
        case 12:
            if (self->d1e0 == 1) {
                self->fn_52_32F4();
                self->d56b = 0;
                self->d1e1 = 1;
                self->d568 = 8;
                self->d55d = 0xd;
                return;
            }
            break;
        case 13: {
            if (self->d1e0 == 1) {
                int c = self->d1e1 - 1;
                self->d1e1 = (unsigned char)c;
                if ((unsigned char)c != 0) break;
                self->d568 = 9;
                switch (self->d56b) {
                case 0:
                    self->d1e1 = 3;
                    self->d564 = d[24];
                    self->d5f1 = 7;
                    self->d56b = 1;
                    break;
                case 1:
                    {
                        float r = randf__Fv();
                        float hi = w->f8c;
                        float lo = w->f88;
                        hi = hi - (lo);
                        self->d56b = 2;
                        float t = d[1] + (lo + hi * r) / d[7];
                        int iv = (int)t;
                        self->d1e1 = (unsigned char)iv;
                        self->d56c = (unsigned char)iv;
                    }
                    break;
                case 2:
                    self->d1e1 = 1;
                    self->d56b = 0;
                    self->d55d = 0xe;
                    break;
                default:
                    break;
                }
            }
            if (self->d56b != 0 && self->d5f1 == 7 && self->d564 < (d[25] + w->f80)) {
                self->d5f1 = 0;
            }
            float pv = self->d564;
            if ((pv < d[25]) && (pv > d[7]))
                self->d604 = d[14];
            else
                self->d604 = d[1];
            fn_27_233C70(self->d5fc, self->d600);
            switch (self->d56b) {
            case 1: {
                float q = self->d564;
                if (q < d[26]) {
                    self->d60a = 1;
                    self->d60b = 7;
                } else if (q < d[27]) {
                    self->d60b = 0;
                } else if (q < d[28]) {
                    self->d60b = 1;
                } else if (q < d[25]) {
                    self->d609 = 1;
                    self->d60a = 7;
                    self->d60b = 0;
                } else {
                    self->d609 = 0;
                    self->d60a = 0;
                }
                break;
            }
            case 2:
                self->d564 = d[7];
                break;
            default:
                break;
            }
            break;
        }
        case 14:
            if (self->d1e0 == 1) {
                int c = self->d1e1 - 1;
                self->d1e1 = (unsigned char)c;
                if ((unsigned char)c != 0) break;
                self->d569 = self->d568;
                self->fn_52_2818(dt);
                self->fn_52_28B8(dt);
            }
            {
                float q = self->d564;
                if (q < d[29]) {
                    self->d609 = 0;
                    self->d60a = 0;
                } else if (q < d[7]) {
                    self->d60a = 7;
                } else {
                    self->d609 = 0;
                    self->d60a = 0;
                }
            }
            return;
        default:
            break;
        }
    }
}
}
