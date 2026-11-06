#include <gf/gf_archive.h>
#include <st/st_positions.h>
#include <cm/cm_camera_controller.h>
#include <gf/gf_camera.h>
#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" const char lbl_40_data_15B8[];
extern "C" const char lbl_40_data_15D8[];
extern "C" char* g_ftManager;
extern "C" float lbl_40_rodata_58;

struct ByteFlags { unsigned char rest : 7; unsigned char bit : 1; };
struct Object_vptr_4_base { char pad[4]; };
class Object_vptr_4 : public Object_vptr_4_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
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
    virtual void slot40();
    char pad40[0x50];
    stPositions* positions;
    char pad94[0x10c];
    gfArchive* archive;
    char pad1a4[0x388];
    int state;
    char pad530[0x20];
    struct { unsigned char bit : 1; unsigned char rest : 7; } flags;
};

extern "C" void fn_40_50DC(Object_vptr_3c* self, unsigned int id) {
    if (id != 0xff) {
        void* data = self->archive->getData(Data_Type_Model, id, 0xfffe);
        if (data) {
            nw4r::g3d::ResFile res((nw4r::g3d::ResFileData*)data);
            self->positions->loadPositionData(&res);
        }
    }
    *((unsigned char*)self->positions + 0x61) = 0;
    self->flags.bit = 0;
    self->state = 1;
    self->slot40();
    if (CameraController::getInstance()) {
        CameraController::getInstance()->changeInput(CameraController::AI);
        gfCameraManager* manager = gfCameraManager::getManager();
        manager->m_cameras[0].m_far = lbl_40_rodata_58;
        Object_vptr_4* p = (Object_vptr_4*)__dynamic_cast(*(void**)((char*)CameraController::getInstance() + 0x48), 4, lbl_40_data_15B8, lbl_40_data_15D8, 0);
        p->slot3();
        ((ByteFlags*)((char*)p + 0x94))->bit = 0;
        *(unsigned char*)(g_ftManager + 0x6e) &= ~2;
    }
}
