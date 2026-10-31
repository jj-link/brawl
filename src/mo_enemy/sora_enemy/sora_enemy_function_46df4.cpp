#pragma force_active on
typedef unsigned int u32;
typedef unsigned long long u64;
struct V3 {
    float x,y,z;
    V3() {}
    V3(float a,float b,float c) : x(a),y(b),z(c) {}
    void set(float a, float b) { x=a; y=b; }
    V3& operator=(const V3& o) { x=o.x; y=o.y; z=o.z; return *this; }
};
struct V2 { float x,y; };
union V2Bits { u64 bits; V2 v; };
class Posture {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual V3 getPos();
};
struct Modules { char pad[0xC]; Posture* posture; };
struct Accesser { char pad[0xD8]; Modules* modules; };
struct Params {
    char pad[0x20];
    float range;
    float speed[2];
    float turn[2];
    char pad34[8];
    u32 frame;
};
struct SpeedData { char pad[0x58]; float accel; };
struct Wnem {
    char pad[0x2184];
    SpeedData* speedData;
    char pad2188[0x70];
    float vx,vy;
    char pad2200[0x14];
    bool entered;
    char pad2215[0x1F];
    Params* params;
};
extern "C" {
extern char lbl_41_data_EB70[];
extern const float lbl_41_rodata_FE4;
extern const float lbl_41_rodata_1000;
void Report__14wnemCommonProcFPCce(const char*, ...);
u32 getFrameCounter__10wnemSimpleFl(Wnem*, int);
void* fn_41_2C7C4(V3*, float);
void getHipPos__23ftExternalValueAccesserFP7Fighter(V3*, void*);
void fn_41_534C(V3*, const V3*);
float fn_41_33B6C(float*, Accesser*);
u64 fn_41_43FB8(V3*, V3*, V3*, float);
float rsqrtf__Ff(float);
double __fabs(double);

void fn_41_46DF4(Wnem* wn, Accesser* acc) {
    u32 frame;
    float sum;
    Params* data = 0;
    if (wn->params) data = wn->params;
    bool entered = wn->entered;
    wn->entered = false;
    if (entered) Report__14wnemCommonProcFPCce(lbl_41_data_EB70);
    frame = data->frame;
    V3 target;
    V3 pos = acc->modules->posture->getPos();
    V3 motion;
    V3 hip;
    V2 vel;
    V2Bits temp;
    if (getFrameCounter__10wnemSimpleFl(wn, 1) >= frame) {
        float range = data->range;
        void* fighter = fn_41_2C7C4(&pos, range);
        if (fighter) {
            getHipPos__23ftExternalValueAccesserFP7Fighter(&hip, fighter);
            fn_41_534C(&target, &hip);
            target.z = lbl_41_rodata_FE4;
        } else {
            target.x = pos.x + wn->vx;
            target.y = pos.y + wn->vy;
        }
        float maxSpeed = fn_41_33B6C(data->speed, acc);
        float turn = fn_41_33B6C(data->turn, acc);
        SpeedData* sd = wn->speedData;
        motion.set(wn->vx, wn->vy);
        motion.z = lbl_41_rodata_FE4;
        temp.bits = fn_41_43FB8(&target, &pos, &motion, turn);
        u32* vp = (u32*)&vel;
        u32* tp = (u32*)&temp;
        vp[0] = tp[0];
        vp[1] = tp[1];
        float xSq = wn->vx * wn->vx;
        float ySq = wn->vy * wn->vy;
        sum = xSq + ySq;
        float speed;
        if ((float)__fabs(sum) <= lbl_41_rodata_1000)
            speed = lbl_41_rodata_FE4;
        else speed = sum * rsqrtf__Ff(sum);
        speed = sd->accel + speed;
        if (speed >= maxSpeed) speed = maxSpeed;
        vel.x *= speed;
        vel.y *= speed;
        wn->vx = vel.x;
        wn->vy = vel.y;
    }
}
}
