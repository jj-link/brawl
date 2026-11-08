#include <cm/cm_camera_controller.h>
#pragma force_active on

extern "C" {
extern const float lbl_104_rodata_60;
extern const float lbl_104_rodata_64;
CameraController* getInstance__16CameraControllerFv();
}

class Class_7FC8 {
public:
    virtual void fn_104_7930();
    virtual void fn_104_12090();
    virtual void fn_104_12990();
    virtual void fn_104_12988();
    virtual void fn_104_12980();
    virtual void fn_104_12978(int);
    virtual void fn_104_12970();
    virtual int fn_104_12968(int);
    virtual void fn_104_12960();
    virtual void fn_104_12958();
    virtual void fn_104_12950(int, Vec3f*, Vec3f*);
    virtual void fn_104_12948();
    virtual void fn_104_12940();
    virtual void fn_104_12938();
    virtual void fn_104_128E8();
    virtual void fn_104_12930(int, int);
    virtual void fn_104_12920();
    virtual int fn_104_12910(int);
    virtual void fn_104_12900(int);
    virtual void fn_104_128F0(int);
};

class FloatSource {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float getFloat();
};

class Entity {
public:
    char pad[0x3c];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual int getKind();
};

class CameraInput {
public:
    char pad[8];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual Vec3f getPos(int, int);
};

struct Data {
    char p0[4];
    CameraInput* input;
    char p1[4];
    FloatSource* timer;
    char p2[0x24];
    Class_7FC8* anim;
    char p3[0x2c];
    Class_7FC8* model;
    char p4[0x1c];
    Class_7FC8* camera;
};

struct Fighter {
    char pad[8];
    Entity* entity;
    char pad2[0xcc];
    Data* data;
};

#pragma always_inline on

inline int getKind(Entity* entity) {
    return entity->getKind();
}

inline Vec3f getPosition(CameraInput* input, int frame) {
    return input->getPos(frame, 0);
}

extern "C" void fn_104_F72C(void*, Fighter* arg1) {
    Class_7FC8* anim = arg1->data->anim;
    int value;
    if (anim->fn_104_12968(0)) {
        if (arg1->data->model->fn_104_12910(0x22000012)) {
            anim->fn_104_12978(0);
            anim = 0;
            switch (getKind(arg1->entity)) {
            case 13:
                anim = reinterpret_cast<Class_7FC8*>(3);
                break;
            case 14:
                anim = reinterpret_cast<Class_7FC8*>(5);
                break;
            }
            arg1->data->camera->fn_104_12930(
                reinterpret_cast<int>(anim), 0);
            arg1->data->model->fn_104_128F0(0x22000012);
        } else {
            value = 0;
            switch (getKind(arg1->entity)) {
            case 13:
                value = 0x45;
                break;
            case 14:
                value = 0x1e;
                break;
            }
            float f = arg1->data->timer->getFloat();
            Vec3f pos = getPosition(arg1->data->input, value);
            pos.m_z = lbl_104_rodata_60;
            Vec3f target = pos;
            CameraController* controller = getInstance__16CameraControllerFv();
            target.m_x = lbl_104_rodata_64 == f
                ? *reinterpret_cast<float*>(
                      reinterpret_cast<char*>(controller) + 0x14c)
                : *reinterpret_cast<float*>(
                      reinterpret_cast<char*>(controller) + 0x148);
            anim->fn_104_12950(0, &pos, &target);
            arg1->data->model->fn_104_12900(0x22000012);
        }
    }
}
