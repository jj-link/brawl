#pragma force_active on
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" unsigned char lbl_63_data_920[];
extern "C" const float lbl_63_rodata_30;

struct Flags { unsigned int pad; unsigned int flags; };
class Class_3138 {
public:
    virtual void fn_63_D57C();
    virtual void fn_63_CA44();
    virtual void fn_63_CA54();
    virtual void fn_63_AF3C();
    virtual void fn_63_AB04(int, int);
    Flags* data;
    unsigned int state;
};
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void slot2();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void slot14();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();

    char pad40[0x90];
    Class_3138 part;
    char padDC[0x74];
    unsigned char a150;
    char pad151[3];
    float a154;
    int a158;
    unsigned char a15c;
    unsigned char a15d;
    char pad15e[2];
    float a160;
    float a164;
    float a168;
    float a16c;
    float a170;
};
extern "C" Ground* fn_63_2B6C(Ground* p, const char* name) {
    __ct__10grYakumonoFPCc(p, name);
    *(unsigned char**)((char*)p + 0x3c) = lbl_63_data_920;
    p->a150 = 0;
    float zero = lbl_63_rodata_30;
    p->a154 = zero;
    p->a158 = 0;
    p->a15c = 4;
    p->a15d = 1;
    p->a160 = zero;
    p->a164 = zero;
    p->a168 = zero;
    p->a16c = zero;
    p->a170 = zero;
    Class_3138* q = &p->part;
    if (!q)
        return p;
    q->state = 1;
    q->fn_63_AB04(0, 15);
    q->data->flags |= 4;
    p->setupMelee();
    return p;
}