#pragma force_active on
#pragma always_inline on
#pragma inline_depth(8)
struct Vec3 { float x,y,z; Vec3() {} Vec3& operator=(const Vec3& o) { x=o.x; y=o.y; z=o.z; return *this; } void copy(const Vec3&); };
struct Vec2 { float x,y; };
class EnergyModule {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void* getEnergy(int);
};
class Posture {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual Vec3 getPos();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual float getLr();
};
class Team {
public:
    virtual void f0();
    virtual void f1();
    virtual int getId();
};
class TeamModule {
public:
    virtual void f0();
    virtual void f1();
    virtual Team* getTeam();
};
class Work {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void setFlag(int, unsigned int);
};
struct Modules {
    char pad0[0xC];
    Posture* posture;
    char pad1[8];
    TeamModule* team;
    char pad2[0x48];
    Work* work;
    char pad3[0x14];
    EnergyModule* kinetic;
};
struct Accesser {
    char pad[0xD8]; Modules* modules;
};
struct Energy { char pad[8]; float x,y; };
extern "C" {
extern const unsigned char lbl_112_rodata_90[];
extern char lbl_112_data_8D64[], lbl_112_data_1CEC[];
extern void* g_ftManager;
extern char* lbl_27_bss_5668;
void* __dynamic_cast(void*,long,const void*,const void*,short);
void* searchNearFighter__9ftManagerFffP5Vec3fib(void*,Vec3*,float,float,int,bool);
Vec3 getPos__23soExternalValueAccesserFP11StageObject(void*);
void fn_112_12974(Vec3*,const Vec3*);
int fn_112_132F4(double);
void fn_8003DBA8(Vec2*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(Accesser*,unsigned long,unsigned long);

}
inline void Vec3::copy(const Vec3& o) {fn_112_12974(this,&o);}
inline const Vec3* fallbackPosition() { return (const Vec3*)(*(char**)(lbl_27_bss_5668+0x78)+0x20); }
extern "C" {
void fn_112_130F0(void*, Accesser* a) {
    const float* constants = reinterpret_cast<const float*>(lbl_112_rodata_90);
    Energy* energy = (Energy*)__dynamic_cast(a->modules->kinetic->getEnergy(2),0,lbl_112_data_8D64,lbl_112_data_1CEC,1);
    Vec3 pos = a->modules->posture->getPos();
    void* manager = g_ftManager;
    int id = a->modules->team->getTeam()->getId();
    void* target = searchNearFighter__9ftManagerFffP5Vec3fib(manager,&pos,constants[0],constants[1],id,true);
    Vec3 targetPos;
    if (target) {
        Vec3 temp = getPos__23soExternalValueAccesserFP11StageObject(target);
        targetPos.copy(temp);
    } else {
        targetPos.copy(*fallbackPosition());
    }
    Vec2 speed;
    speed.x = targetPos.x-pos.x;
    speed.y = targetPos.y-pos.y;
    int zero = 0;
    if (fn_112_132F4(speed.x) && fn_112_132F4(speed.y)) zero = 1;
    if (!zero) fn_8003DBA8(&speed);
    else speed.y = constants[2];
    float scale = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a,0xFA3,0);
    speed.x *= scale;
    speed.y *= scale;
    energy->x = speed.x;
    energy->y = speed.y;
    if (speed.x*a->modules->posture->getLr() < constants[0]) {
        a->modules->work->setFlag(1,0x22000000);
    }
}
}