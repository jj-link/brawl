#include <gf/gf_archive.h>
#include <st/st_positions.h>
#include <cm/cm_camera_controller.h>
#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void fn_800A59C4(void*);
extern "C" void fn_800A5990(void*, float*);
extern "C" const char lbl_40_data_1590[];
extern "C" const char lbl_40_data_15D8[];
extern "C" char* g_ftManager;

struct Flags8 { unsigned int a:8; unsigned int b:8; unsigned int c:16; };
struct Stage_base { char pad[0x3c]; };
class Stage : public Stage_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_40_2024();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void fn_40_21B8();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void fn_40_222C();
    virtual void renderPre();
    virtual void fn_40_8A84();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_40_12F8();
    virtual void fn_40_D24();
    virtual void createObjPokeTrainer();
    virtual void fn_40_5098();
    virtual void fn_40_50A0();
    virtual void fn_40_50BC();
    virtual void fn_40_8B18();
    virtual void fn_40_8B28();
    virtual void fn_40_7D94();
    virtual void fn_40_8154();
    virtual void fn_40_80AC();
    virtual void fn_40_8160();
    virtual void fn_40_8478();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_40_45C();
    virtual void process();
    virtual void fn_40_7D44();

    char pad40[0x90-0x40];
    stPositions* positions;
    char pad94[0x1a0-0x94];
    gfArchive* archive;
    char pad1a4[0x1c0-0x1a4];
    char* data;
    char pad1c4[0x52c-0x1c4];
    int state;
    char pad530[0x550-0x530];
    struct { unsigned char bit : 1; unsigned char rest : 7; } flags;
};

extern "C" void fn_40_51F4(Stage* self, int id) {
    void* data = self->archive->getData(Data_Type_Model, id, 0xfffe);
    if (data) {
        nw4r::g3d::ResFile res((nw4r::g3d::ResFileData*)data);
        self->positions->loadPositionData(&res);
    }
    *((unsigned char*)self->positions + 0x61) = 0;
    self->state = 1;
    self->flags.bit = 0;
    self->fn_40_7D44();
    if (CameraController::getInstance()) {
        char* p = (char*)__dynamic_cast(*(void**)((char*)CameraController::getInstance() + 0x48), 4, lbl_40_data_1590, lbl_40_data_15D8, 0);
        if (p) {
            ((Flags8*)(p + 8))->b = 2;
            *(unsigned char*)(p + 0x144) = 1;
            fn_800A59C4(p);
        }
        p = (char*)__dynamic_cast(*(void**)((char*)CameraController::getInstance() + 0x48), 4, lbl_40_data_1590, lbl_40_data_15D8, 0);
        if (p && self->data) {
            *(float*)(p + 0xdc) = *(float*)(self->data + 0x1c);
            fn_800A5990(p, (float*)(self->data + 0x20));
        }
        *(unsigned char*)(g_ftManager + 0x6e) &= ~2;
    }
}