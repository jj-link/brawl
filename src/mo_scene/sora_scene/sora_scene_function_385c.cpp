#pragma force_active on
extern "C" {

extern void** g_stLoaderManager;
extern int fn_27_23EB6C(void*);

struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
public:
    virtual int processDefault();
    virtual int fn_1_8AE0();
    virtual int processAnim();
    virtual int processUpdate();
    virtual int processPreMapCorrection();
    virtual int processMapCorrection();
    virtual int processFixPosition();
    virtual int processPreCollision();
    virtual int processCollision();
    virtual int processCatch();
    virtual int processHit();
    virtual int processCamera();
    virtual int processFixCamera();
    virtual int processEffect();
    virtual int processGameProc();
    virtual int processEnd();
    virtual int renderPre();
    virtual int renderOpa();
    virtual int renderXlu();
    virtual int processDebug();
    virtual int renderDebug();
    virtual int init();
    virtual int fn_1_8B3C();
    virtual int fn_1_8ADC();
    virtual int fn_1_8AD4();
    virtual int fn_1_8ACC();
    virtual int fn_1_8AC8();
};

int fn_1_385C(int arg0) {
    int off = 0;
    int i = 0;
    while (i < 7) {
        void* p = *(void**)((char*)g_stLoaderManager + off);
        if (p != 0 && ((gfTask*)p)->fn_1_8AC8() == 0) {
            if (arg0 == 0) {
                void* q = *(void**)((char*)g_stLoaderManager + off);
                if (((gfTask*)q)->fn_1_8ACC() == 0) return 0;
            } else {
                void* q = *(void**)((char*)g_stLoaderManager + off);
                if (fn_27_23EB6C(q) == 0) return 0;
            }
        }
        i++;
        off += 4;
    }
    return 1;
}

}