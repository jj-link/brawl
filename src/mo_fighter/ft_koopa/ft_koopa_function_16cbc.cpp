#pragma force_active on
struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(float a, float b) : x(a), y(b) {}
};
inline Vec2* tempVec(const Vec2& v) { return const_cast<Vec2*>(&v); }
inline void assign(Vec2* dst, const Vec2& src) { dst->x = src.x; dst->y = src.y; }
struct Vec3 { float x, y, z; };
struct Flag { unsigned short mask; };
struct Accesser;
class Work {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual bool isFlag(unsigned int);
    virtual void onFlag(unsigned int); virtual void offFlag(unsigned int);
};
class Energy {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void reset(int, Vec2*, Vec3*, Accesser*);
    unsigned char state, flags; char pad[10];
    float a, b, c, d, e, f;
};
class Kinetic {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual Energy* getEnergy(int);
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual Vec2 getSum(const Flag&);
};
struct Modules { char pad[0x64]; Work* work; char pad2[0x14]; Kinetic* kinetic; };
struct Accesser { char pad[0xd8]; Modules* modules; };
struct Params { float x, y, z, a, b, c; };
extern "C" {
extern char g_ftCommonDataAccesser;
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
extern const char lbl_102_data_5E6C[], lbl_102_data_5D8C[], lbl_102_data_14F4[];
extern const float lbl_102_rodata_68;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_102_169B4(Accesser*);
void fn_102_16A7C(Accesser*);
Vec3* fn_102_C5B8(Vec3*, float, float, float);
}
extern "C" void fn_102_16CBC(void*, Accesser* accesser) {
    Work* work = accesser->modules->work;
    if (work->isFlag(0x1200003d)) {
        fn_102_16A7C(accesser);
        work->offFlag(0x1200003d);
    }
    Params* params = *(Params**)((char*)getData__20ftCommonDataAccesserCF6ftKind(&g_ftCommonDataAccesser, 0x30) + 0x88);
    Flag flag; flag.mask = 1;
    Vec2 speed;
    __memcpy(&speed, &accesser->modules->kinetic->getSum(flag), sizeof(speed));
    if (!work->isFlag(0x22000012)) {
        speed.x *= params->x;
        speed.y *= params->y;
        fn_102_169B4(accesser);
        Energy* gravity = (Energy*)__dynamic_cast(accesser->modules->kinetic->getEnergy(1), 0, lbl_102_data_5E6C, lbl_102_data_14F4, 1);
        Vec3 rot;
        gravity->reset(0, tempVec(Vec2(lbl_102_rodata_68, speed.y)), fn_102_C5B8(&rot, lbl_102_rodata_68, lbl_102_rodata_68, lbl_102_rodata_68), accesser);
        gravity->a = params->a;
        gravity->b = params->b;
        gravity->d = params->b;
        gravity->flags |= 0x80;
        Energy* stop = (Energy*)__dynamic_cast(accesser->modules->kinetic->getEnergy(3), 0, lbl_102_data_5D8C, lbl_102_data_14F4, 1);
        Vec3 rot2;
        stop->reset(9, tempVec(Vec2(speed.x, lbl_102_rodata_68)), fn_102_C5B8(&rot2, lbl_102_rodata_68, lbl_102_rodata_68, lbl_102_rodata_68), accesser);
        assign((Vec2*)&stop->e, Vec2(params->z, lbl_102_rodata_68));
        stop->flags |= 0x80;
    } else {
        speed.y = params->c;
        fn_102_169B4(accesser);
        Energy* gravity = (Energy*)__dynamic_cast(accesser->modules->kinetic->getEnergy(1), 0, lbl_102_data_5E6C, lbl_102_data_14F4, 1);
        Vec3 rot;
        gravity->reset(0, tempVec(Vec2(lbl_102_rodata_68, params->c)), fn_102_C5B8(&rot, lbl_102_rodata_68, lbl_102_rodata_68, lbl_102_rodata_68), accesser);
        gravity->a = lbl_102_rodata_68;
        gravity->flags |= 0x80;
        work->onFlag(0x22000011);
    }
}