#pragma force_active on
struct PitVec { float x; float y; float z; };

extern "C" void fn_112_12974(PitVec* dst, const PitVec* src);

class PitPosture {
public:
    virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14();
    virtual PitVec getPos();
    virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28();
    virtual void v2C(); virtual void v30(); virtual void v34(); virtual void v38();
    virtual void v3C();
    virtual PitVec getRot(int);
    virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual float getScale();
};

struct PitModelBase { int a; int b; };
class PitModel : public PitModelBase {
public:
    virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void setSRT(int, PitVec*, PitVec*, PitVec*);
};

struct PitModules { char pad0[4]; PitModel* model; char pad8[4]; PitPosture* posture; };
struct PitObj2 { char pad[0xD8]; PitModules* modules; };
struct PitOwner { char pad[0x60]; PitObj2* obj; };

inline void copyVec(PitVec* dst, const PitVec& src) { fn_112_12974(dst, &src); }

extern "C" void fn_112_15E24(PitOwner* arg0) {
    PitObj2* obj = arg0->obj;
    PitVec scale;
    PitVec rot;
    PitVec pos;
    float s = obj->modules->posture->getScale();
    scale.z = s;
    scale.y = s;
    scale.x = s;
    copyVec(&pos, obj->modules->posture->getPos());
    copyVec(&rot, obj->modules->posture->getRot(0));
    obj->modules->model->setSRT(0, &scale, &rot, &pos);
}
