#include <types.h>
#include <cm/cm_camera_controller.h>
#include <gf/gf_camera.h>
#include <st/st_positions.h>
#pragma force_active on

extern "C" {
void fn_27_227B68(void*, u8);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_800A59C4(void*);
void fn_800A5704(void*);
void fn_800A4BA8(void*, void*);
void fn_800A5990(void*, float*);
extern const char lbl_40_data_1590[];
extern const char lbl_40_data_15D8[];
extern char* g_ftManager;
}
struct Flags8 { unsigned int a:8; unsigned int b:8; unsigned int c:16; };
struct V4 { float x, y, z, w; };
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
    virtual void slot40(unsigned int);
    char pad40[0x90-0x40];
    stPositions* positions;
    char pad94[0x1c0-0x94];
    char* data;
    char pad1c4[4];
    char* data2;
    char pad1cc[0x52c-0x1cc];
    int state;
    char pad530[0x550-0x530];
    u8 flags;
};
extern "C" void fn_40_533C(Object_vptr_3c* self) {
    fn_27_227B68(self->positions, (self->flags >> 6) & 1);
    u8 flags = self->flags | 0x80;
    self->state = 0;
    self->flags = flags;
    self->slot40(flags);
    CameraController::getInstance()->changeInput(CameraController::Adventure);
    if (CameraController::getInstance()) {
        char* p = (char*)__dynamic_cast(*(void**)((char*)CameraController::getInstance() + 0x48), 4, lbl_40_data_1590, lbl_40_data_15D8, 0);
        ((Flags8*)(p + 8))->b = 0;
        *(u8*)(p + 0x144) = 1;
        fn_800A59C4(p);
        fn_800A5704(p);
        gfCameraManager* manager = gfCameraManager::getManager();
        float z, y, x;
        x = manager->m_cameras[0].m_targetPos.m_x;
        y = manager->m_cameras[0].m_targetPos.m_y;
        z = manager->m_cameras[0].m_targetPos.m_z;
        Vec3f pos(x, y, z);
        self->positions->m_centerPos = pos;
        p = (char*)__dynamic_cast(*(void**)((char*)CameraController::getInstance() + 0x48), 4, lbl_40_data_1590, lbl_40_data_15D8, 0);
        if (p && self->data2) {
            fn_800A4BA8(p, self->data2 + 8);
        }
        if (p && self->data) {
            *(float*)(p + 0xdc) = *(float*)(self->data + 4);
            fn_800A5990(p, (float*)(self->data + 8));
            float fw, fz, fy, fx;
            fy = *(float*)(self->data + 0x10);
            fx = *(float*)(self->data + 0xc);
            fw = *(float*)(self->data + 0x18);
            fz = *(float*)(self->data + 0x14);
            V4 v = {fx, fy, fz, fw};
            *(float*)(p + 0xe8) = v.x;
            *(float*)(p + 0xec) = v.y;
            *(float*)(p + 0xf0) = v.z;
            *(float*)(p + 0xf4) = v.w;
        }
        *(u8*)(g_ftManager + 0x6e) |= 2;
    }
}
