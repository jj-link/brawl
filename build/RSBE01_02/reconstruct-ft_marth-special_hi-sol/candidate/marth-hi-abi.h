#pragma once

// Private compiler continuation: only the ABI surface read by this unit.
// Virtual order and field offsets follow the existing so headers and original object.
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
class soModuleAccesser;
struct Vec2f {
    float m_x, m_y;
    Vec2f() {}
    Vec2f(float x, float y) : m_x(x), m_y(y) {}
};
struct Vec3f { float m_x, m_y, m_z; Vec3f() {} };
class soNullable {
public:
    virtual bool isNull() const;
    bool m_isNull;
};
class soEnable {
    u8 m_isEnable : 1;
public:
    bool isEnable() const { return m_isEnable; }
    void disable() { m_isEnable = 0; }
};
class soKineticEnergy : public soNullable, public soEnable {
public:
    struct AttributeFlag { u16 m_mask; };
    virtual void updateEnergy(soModuleAccesser*);
    virtual Vec2f getSpeed();
    virtual Vec3f getSpeed3f();
    virtual Vec3f getRotation();
    virtual void resetEnergy(int, Vec2f*, Vec3f*, soModuleAccesser*);
    virtual void clearSpeed();
    virtual void clearRotSpeed();
    virtual void mulSpeed(Vec3f*);
    virtual void mulAccel(Vec3f*);
    virtual void reflectSpeed(Vec3f*);
    virtual void reflectAccel(Vec3f*);
    virtual void onConsiderGroundFriction();
    virtual void offConsiderGroundFriction();
    virtual ~soKineticEnergy();
};
class soKineticModule : public soNullable {
public:
    virtual void activate();
    virtual void deactivate();
    virtual void addEnergy(soKineticEnergy*, int, soKineticEnergy::AttributeFlag, short);
    virtual void eraseEnergy(int);
    virtual void eraseEnergyAll();
    virtual soKineticEnergy* getEnergy(int);
};
struct Input;
class soControllerModule {
public:
    virtual ~soControllerModule();
    virtual void activate();
    virtual void deactivate();
    virtual void resetButton();
    virtual void resetTrigger();
    virtual void resetMainStickX();
    virtual void setMainStickX(float);
    virtual void resetMainStickY();
    virtual void setMainStickY(float);
    virtual void resetMainStick();
    virtual void resetSubStickX();
    virtual void resetSubStickY();
    virtual void resetSubStick();
    virtual void update(Input*, bool);
    virtual void resetFlickX();
    virtual void resetFlickY();
    virtual float getStickX();
};
class soSituationModule {
public:
    virtual ~soSituationModule();
    virtual void activate();
    virtual void deactivate();
    virtual int getKind();
};
class soMotionModule {
public:
    virtual ~soMotionModule();
    virtual void activate();
    virtual void deactivate();
    virtual void setData(void*);
    virtual void updateFrame(float);
    virtual void updateNode();
    virtual float getRate();
    virtual void setRate(float);
    virtual void setLoopFlag(bool);
    virtual bool isLoopFlag();
    virtual void setFrame(float);
    virtual void setFrameSyncAnimCmd(float);
    virtual float getFrame();
    virtual bool isAnimResFile(int);
    virtual float getEndFrame(int);
    virtual float getEndFrame();
    virtual bool isEnd();
    virtual bool isLooped();
    virtual bool isAnimCmd(int);
    virtual char* getName(int, bool);
    virtual char* getName();
    virtual int getKind();
};
class soGeneralWorkAbstract;
class soWorkManageModule : public soNullable {
public:
    virtual ~soWorkManageModule();
    virtual void activate();
    virtual void setWork(u32, soGeneralWorkAbstract*);
    virtual int getInt(u32);
    virtual void setInt(int, u32);
    virtual void rndInt(int, int, u32);
    virtual void incInt(u32);
    virtual void decInt(u32);
    virtual void addInt(int, u32);
    virtual void subInt(int, u32);
    virtual u32 countDownInt(u32, int);
    virtual float getFloat(u32);
    virtual void setFloat(float, u32);
    virtual void rndFloat(float, float, u32);
    virtual void addFloat(float, u32);
    virtual void subFloat(float, u32);
    virtual bool isFlag(u32);
    virtual void onFlag(u32);
    virtual void offFlag(u32);
};
struct MarthHiModuleEnumeration {
    void* unknown00[2];
    soMotionModule* motion;
    void* unknown0C[2];
    soSituationModule* situation;
    void* unknown18[17];
    soControllerModule* controller;
    void* camera;
    soWorkManageModule* work;
    void* unknown68[5];
    soKineticModule* kinetic;
};
class soModuleAccesser {
    u8 unknown00[0xD8];
    const MarthHiModuleEnumeration* enumeration;
public:
    soKineticModule& getKineticModule() const { return *enumeration->kinetic; }
    soSituationModule& getSituationModule() const { return *enumeration->situation; }
    soControllerModule& getControllerModule() const { return *enumeration->controller; }
    soWorkManageModule& getWorkManageModule() const { return *enumeration->work; }
    soMotionModule& getMotionModule() const { return *enumeration->motion; }
};
class soValueAccesser {
public:
    static float getConstantFloat(soModuleAccesser*, u32, u32);
};
class soStatusUniqProcess {
public:
    virtual ~soStatusUniqProcess() {}
    virtual void initStatus(soModuleAccesser*);
    virtual void exitStatus(soModuleAccesser*, int);
    virtual void execStatus(soModuleAccesser*);
    virtual void execStop(soModuleAccesser*);
    virtual void execMapCorrection(soModuleAccesser*);
    virtual void execFixPosCounter(soModuleAccesser*);
    virtual void execFixPos(soModuleAccesser*);
    virtual void execFixCamera(soModuleAccesser*);
    virtual bool checkDamage(soModuleAccesser*, void*);
    virtual void checkAttack(soModuleAccesser*, void*, float);
    virtual bool onChangeLr(soModuleAccesser*, float, float);
    virtual void leaveStop(soModuleAccesser*, int, bool);
    virtual bool checkTransitionPrecede(soModuleAccesser*, int*);
};
typedef char MarthHiEnergySize[(sizeof(soKineticEnergy) == 8) ? 1 : -1];
typedef char MarthHiVec2Size[(sizeof(Vec2f) == 8) ? 1 : -1];
typedef char MarthHiAccessorSize[(sizeof(soModuleAccesser) == 0xDC) ? 1 : -1];
