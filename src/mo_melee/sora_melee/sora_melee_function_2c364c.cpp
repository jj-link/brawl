#include <mu/mu_msg.h>
#include <gf/gf_application.h>
#pragma force_active on

struct CallbackBase { char pad[0x3C]; };
class Callback : public CallbackBase {
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
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void end(int);
};
struct State {
    char pad0[0x40];
    Callback* callback;
    char pad44[8];
    int state;
    char pad50[4];
    void* resource;
    char pad58[4];
    MuMsg* msg;
    int index;
    unsigned char finished;
    char pad65[3];
    float timer;
    float delay;
    char pad70[0x100];
    int enabled;
    char pad174[0x18];
    void* object;
    unsigned int* durations;
    unsigned int frames;
};
extern "C" {
    int fn_800B61C0(void*);
    void fn_800B932C(MuMsg*, int);
    int fn_800B955C(MuMsg*, int, int*);
    short fn_27_2C2D24(int);
    void fn_8007B058(void*, short);
    extern const char lbl_27_data_7B230[];
    extern const float lbl_27_rodata_6048;
    extern const float lbl_27_rodata_6018;
}
extern "C" void fn_27_2C364C(State* self) {
    if ((*(unsigned int*)((char*)g_gfApplication + 0xEC) >> 27) != 0 || ((*(unsigned char*)((char*)g_gfApplication + 0xEE) >> 7) & 1)) return;
    if (self->msg == 0) return;
    if (self->state == 3) {
        if (fn_800B61C0(self->resource)) {
            self->msg->printf(0, lbl_27_data_7B230);
            fn_800B932C(self->msg, 0);
            self->msg->printf(1, lbl_27_data_7B230);
            fn_800B932C(self->msg, 1);
            self->state = 4;
        }
    } else if ((unsigned int)(self->state - 1) <= 1) {
        int value;
        if (self->index >= 0 && self->enabled != 0 && self->object != 0 &&
            fn_800B955C(self->msg, 1, &value)) {
            short id = fn_27_2C2D24(value);
            if (id != 0xD3) fn_8007B058(self->object, id);
        }
        if (self->index >= 0 && self->finished == 0) {
            ++self->frames;
            self->msg->isEndDelayPrint(1);
            unsigned int duration = 0;
            if (self->index >= 0) duration = self->durations[self->index];
            bool end = (float)self->frames >= (float)duration - self->delay;
            if (end) {
                self->timer -= lbl_27_rodata_6048;
                if (self->timer < lbl_27_rodata_6018) {
                    Callback* callback = self->callback;
                    self->timer = lbl_27_rodata_6018;
                    self->delay = lbl_27_rodata_6018;
                    self->finished = 1;
                    self->enabled = 0;
                    if (callback) callback->end(self->index);
                }
            }
        }
    }
}
