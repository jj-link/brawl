#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern const float lbl_27_rodata_25D8;

class soPostureModuleImpl {
public:
    virtual void isNull();
    virtual ~soPostureModuleImpl();
    virtual void fn_27_2362C();
    virtual void fn_27_236B0();
    virtual Vec3f fn_27_25088();
    virtual void fn_27_23E84();
    virtual void fn_27_25184();
    virtual void fn_27_2370C();
    virtual void fn_27_23728();
    virtual void fn_27_23E28();
    virtual void fn_27_23CC0();
    virtual void fn_27_25068();
    virtual void fn_27_23A9C();
    virtual void fn_27_23B18();
    virtual void fn_27_250FC();
    virtual void fn_27_250A4();
    virtual void fn_27_23BF8();
    virtual void fn_27_251B8();
    virtual void fn_27_251B0();
    virtual void fn_27_23C14();
    virtual void fn_27_25154();
    virtual void fn_27_2517C();
    virtual float fn_27_23744();
};

class soSoundModuleImpl {
public:
    virtual ~soSoundModuleImpl();
    virtual void update(Vec3f* pos);
    virtual void deactivate();
    virtual void activate(Vec3f* pos);
    virtual void setPos(Vec3f* pos, int);
    virtual int playSE(int sndId, bool flag, int a3, int a4);
    virtual int playSENo3d(int sndId, bool flag);
    virtual int playSEPos(int sndId, Vec3f* pos, bool flag, int a4, int a5);
    virtual int playStatusSE(int sndId, bool flag, int a3);
};

class soEffectModuleImpl {
public:
    virtual void isNull();
    virtual ~soEffectModuleImpl();
    virtual void activate();
    virtual void deactivate();
    virtual void begin();
    virtual void update(bool flag);
    virtual u32 req(int effectID, Vec3f* pos, Vec3f* rot, float scale, u32 a5, int a6);
};

class soWorkManageModuleImpl {
public:
    virtual void isNull();
    virtual ~soWorkManageModuleImpl();
    virtual void activate();
    virtual void setWork(u32 index, void* generalWork);
    virtual int getInt(u32 index);
    virtual void setInt(int value, u32 index, void* accesser);
};

struct Modules {
    char pad0[0xc];
    soPostureModuleImpl* posture;
    char pad1[0x50 - 0x10];
    soSoundModuleImpl* sound;
    char pad2[0x64 - 0x54];
    soWorkManageModuleImpl* work;
    char pad3[0x88 - 0x68];
    soEffectModuleImpl* effect;
};

struct Object {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_27_18DF54(void*, Object* obj) {
    float scale = obj->modules->posture->fn_27_23744();
    Vec3f src = obj->modules->posture->fn_27_25088();
    Vec3f pos;
    Vec3f rot;
    float y = src.m_y;
    rot.m_x = lbl_27_rodata_25D8;
    rot.m_y = lbl_27_rodata_25D8;
    rot.m_z = lbl_27_rodata_25D8;
    pos.m_x = src.m_x;
    pos.m_y = y;
    pos.m_z = lbl_27_rodata_25D8;
    int effectId = (int)obj->modules->effect->req(0x1030016, &pos, &rot, scale, 0, -1);
    obj->modules->work->setInt(effectId, 0x20000000, obj->modules);
    int seHandle = obj->modules->sound->playStatusSE(0x2287, false, 0);
    obj->modules->work->setInt(seHandle, 0x20000001, obj->modules);
}
