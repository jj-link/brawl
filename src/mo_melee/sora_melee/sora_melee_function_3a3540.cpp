#include <types.h>
#include <nw4r/math/math_arithmetic.h>
#include <nw4r/ut/ut_algorithm.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" float fn_27_192278(void*, unsigned long);
extern "C" const float lbl_27_rodata_7EA0;
extern "C" const char lbl_27_data_9CAD8[];
extern "C" const char lbl_27_data_9CAE0[];

class ControllerModule {
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
    virtual void c12();
    virtual void c13();
    virtual void c14();
    virtual void c15();
    virtual void c16();
    virtual void c17();
    virtual float getStickY();
};

class WorkModule {
public:
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual float getFloat(u32 index);
    virtual void setFloat(float value, u32 index);
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual bool isFlag(u32 index);
};

struct ModelModuleBase { char pad[8]; };
class ModelModule : public ModelModuleBase {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual Vec3f getNodeTranslate(u32 node);
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void setNodeTranslate(u32 node, Vec3f* trans);
    virtual void m30();
    virtual void m31();
    virtual int getNodeId(const char* name);
    virtual void m33();
    virtual int getCorrectNodeId(u32 id);
};

struct Modules {
    void* m_resource;
    ModelModule* m_model;
    char pad08[0x54];
    ControllerModule* m_controller;
    char pad60[4];
    WorkModule* m_work;
};

struct HolderBase { char pad[0x3C]; };
class Holder : public HolderBase {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual int slot40();
};

struct Accesser {
    char pad0[8];
    Holder* m_holder;
    char padC[0xCC];
    Modules* m_modules;
};

inline void getNode(Accesser* acc, int& node) {
    if (acc->m_holder->slot40() == 5) {
        ModelModule* model = acc->m_modules->m_model;
        node = model->getCorrectNodeId(model->getNodeId(lbl_27_data_9CAD8));
    } else {
        node = acc->m_modules->m_model->getNodeId(lbl_27_data_9CAE0);
    }
}

extern "C" void fn_27_3A3540(void* self, Accesser* acc) {
    float stick = -acc->m_modules->m_controller->getStickY();
    const float zero = lbl_27_rodata_7EA0;
    float cur = acc->m_modules->m_work->getFloat(0x21000004);
    bool flag = false;

    if (acc->m_modules->m_work->isFlag(0x22000011)) {
        if (nw4r::ut::Abs(stick) > zero) {
            float rate = stick * fn_27_192278(acc, 0xFA2);
            float limit;
            if (stick > lbl_27_rodata_7EA0) {
                limit = fn_27_192278(acc, 0xFA0);
            } else {
                limit = -fn_27_192278(acc, 0xFA1);
            }
            cur += rate;
            if (nw4r::ut::Abs(cur) > nw4r::ut::Abs(limit)) {
                cur = limit;
            }
        } else {
            flag = true;
        }
    }

    if (flag || acc->m_modules->m_work->isFlag(0x22000012)) {
        float dec = fn_27_192278(acc, 0xFA3);
        if (cur < lbl_27_rodata_7EA0) {
            cur += dec;
            if (cur > lbl_27_rodata_7EA0) {
                cur = lbl_27_rodata_7EA0;
            }
        } else if (cur > lbl_27_rodata_7EA0) {
            cur -= dec;
            if (cur < lbl_27_rodata_7EA0) {
                cur = lbl_27_rodata_7EA0;
            }
        }
    }

    int node;
    getNode(acc, node);

    Vec3f trans = acc->m_modules->m_model->getNodeTranslate(node);
    trans.m_x = cur;
    acc->m_modules->m_model->setNodeTranslate(node, &trans);

    acc->m_modules->m_work->setFloat(cur, 0x21000004);
}
