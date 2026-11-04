#pragma force_active on

struct Ground_base { char pad[0x3c]; };

class Ground : public Ground_base {
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
    virtual void setVisibility(unsigned long);
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
    virtual void* fn_62_310C();
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
    virtual void disableHit(unsigned long, unsigned long);

    char pad40[4];
    void** model;
    char pad48[0x104];
    void* object;
    char pad150[4];
    float field154;
    char pad158[4];
    float effectTimer;
    char pad160[4];
    float timer;
    float delay;
    char pad16c[0x24];
    char sound[1];
};

struct IceData {
    char pad[0x10];
    float field10;
    char pad14[0x10];
    float field24;
};

extern "C" {

extern const float lbl_62_rodata_F8[];
extern const char lbl_62_data_24D0[];
extern void* g_ecMgr;

void fn_27_26399C(void*);
float randf__Fv();
int playSE__14snd3DGeneratorF5SndIDiii(void*, int, int, int, int);
unsigned long setEffect__5ecMgrF4EfID(void*, int);
void setParent__5ecMgrFUlPQ34nw4r3g3d6ScnMdlPCcb(void*, unsigned long, void*, const char*, bool);
void setEnableCollisionStatus__6GroundFb(Ground*, bool);

void fn_62_9ABC(Ground* self, void*, const float* args) {
    const float* p = lbl_62_rodata_F8;
    IceData* data = static_cast<IceData*>(self->fn_62_310C());
    if (data) {
        float dec = args[1];
        fn_27_26399C(self->object);
        self->timer -= dec * data->field10;
        if (self->timer < p[0]) {
            self->timer = p[0];
        }
        if (p[0] == self->timer) {
            unsigned long effect = setEffect__5ecMgrF4EfID(g_ecMgr, 0x480002);
            setParent__5ecMgrFUlPQ34nw4r3g3d6ScnMdlPCcb(g_ecMgr, effect, *self->model, lbl_62_data_24D0, false);
            playSE__14snd3DGeneratorF5SndIDiii(self->sound, 0x1c81, 0, 0, -1);
            self->setVisibility(0);
            setEnableCollisionStatus__6GroundFb(self, false);
            self->disableHit(0, 0);
            self->field154 = data->field24;
        } else {
            if (p[0] == self->effectTimer) {
                unsigned long effect = setEffect__5ecMgrF4EfID(g_ecMgr, 0x480004);
                setParent__5ecMgrFUlPQ34nw4r3g3d6ScnMdlPCcb(g_ecMgr, effect, *self->model, lbl_62_data_24D0, false);
                self->effectTimer = p[21] + p[15] * randf__Fv();
            }
            playSE__14snd3DGeneratorF5SndIDiii(self->sound, 0x1c80, 0, 0, -1);
            self->delay = p[22] + p[22] * randf__Fv();
        }
    }
}

}