#include <gf/gf_camera.h>
#include <mt/mt_matrix.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(const Vec3f*);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned int);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15(const Vec3f*, int);
    virtual void slot16();
    virtual int slot17(unsigned int);
};

struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
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
    virtual void processCamera();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void init();
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
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
};

struct Modules {
    char pad[0xc];
    Object_vptr_0* posture;
    char pad1[0x54];
    Object_vptr_0* work;
};
struct Owner {
    char pad[8];
    Object_vptr_3c* object;
    char pad1[0xcc];
    Modules* modules;
};

extern float lbl_27_rodata_2270;

extern "C" void fn_27_172E90(void*, Owner* self) {
    Vec3f out;
    Vec3f rot;
    Vec3f in3;
    Matrix src(true);
    Matrix inv(true);
    float f30;
    float f31;
    float fx;
    gfCameraManager* camera;
    if (self->modules->work->slot17(0x22000012)) {
        if (gfCameraManager::getManager()) {
            camera = gfCameraManager::getManager();
        } else {
            camera = 0;
        }
        if (camera) {
            src = *(Matrix*)camera;
            src.inverse(&inv);
            f30 = self->modules->work->slot12(0x2100000a);
            f31 = self->modules->work->slot12(0x21000009);
            fx = self->modules->work->slot12(0x21000008);
            in3.m_x = fx;
            in3.m_y = f31;
            in3.m_z = f30;
            inv.mulPos(&in3, &out);
            self->modules->posture->slot5(&out);
            inv.getRotate(&rot);
            if (self->object->slot40() != 0x12) {
                rot.m_y += lbl_27_rodata_2270;
            }
            self->modules->posture->slot15(&rot, 0);
            self->object->slot43();
        }
    }
}
