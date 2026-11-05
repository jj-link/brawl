#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const char lbl_122_data_774[];
extern const char lbl_122_data_8C98[];
extern const float lbl_122_rodata_68;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void addCallback__15soPhotoCallBackFv(void* self);
void fn_801AAFF0(void*, int);
}

class PostureLike {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void setOwnerScale(float);
};

struct Pad8 {
    int a;
    int b;
};

class ModelLike : public Pad8 {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void* getScnMdl(int);
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void resetLayerType(int);
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void setScaleZ(float);
};

class EffectLike {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void setShieldLike(int);
};

class WorkLike {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void setInt(int, unsigned int);
};

struct SnakeEnum {
    char pad0[4];
    ModelLike* model;
    char pad1[4];
    PostureLike* posture;
    char pad2[0x64 - 0x10];
    WorkLike* workManage;
    char pad3[0x88 - 0x68];
    EffectLike* effect;
};

extern "C" void fn_122_1489C(void*, soModuleAccesser* accesser) {
    ((SnakeEnum*)accesser->m_enumerationStart)->posture->setOwnerScale(lbl_122_rodata_68);
    void* cast = __dynamic_cast(accesser->m_stageObject, 0x3c, lbl_122_data_774, lbl_122_data_8C98, 0);
    if (cast != 0) {
        addCallback__15soPhotoCallBackFv((char*)cast + 0x2D020);
        ((SnakeEnum*)accesser->m_enumerationStart)->model->setScaleZ(lbl_122_rodata_68);
        ((SnakeEnum*)accesser->m_enumerationStart)->effect->setShieldLike(1);
        void* ret = ((SnakeEnum*)accesser->m_enumerationStart)->model->getScnMdl(0);
        if (ret != 0) {
            ((SnakeEnum*)accesser->m_enumerationStart)->workManage->setInt(*((unsigned char*)ret + 0xD0), 0x10000041);
            fn_801AAFF0(ret, 0xFF);
        }
        ((SnakeEnum*)accesser->m_enumerationStart)->model->resetLayerType(5);
    }
}
