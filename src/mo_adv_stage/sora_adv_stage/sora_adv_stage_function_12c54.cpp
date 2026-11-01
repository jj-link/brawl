#include <types.h>
#include <math.h>
#include <em/enemy.h>
#include <st/st_positions.h>
#include <mt/mt_vector.h>
#pragma force_active on

struct Stage_base {
    char pad[0x3c];
};

class Stage : public Stage_base {
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual int fn_40_7134();

    char pad40[0x50];
    stPositions* m_deadPos;
};

struct CameraControllerData {
    char pad[0x40];
    int mode;
    char pad44[0x1c];
    float x;
    float y;
    float z;
};

struct EnemyData {
    char pad0[4];
    void* accesser;
    char pad8[4];
    int state;
    char pad10[8];
    float timer;
};

extern "C" {
extern Vec3f getPos__23soExternalValueAccesserFP11StageObject(void*);
extern void* getManager__15gfCameraManagerFv();
extern CameraControllerData* getInstance__16CameraControllerFv();
extern float fn_8004E94C(void*);
extern int isCanAutoRemove__23emExternalValueAccesserFP5Enemy(void*, Enemy*);
extern int isClipIn__23emExternalValueAccesserFP5Enemy(void*);
extern void* lbl_40_bss_15C;
extern void* lbl_27_bss_5668;
extern void* g_GameGlobal;
extern float lbl_40_rodata_1B0[];
}

extern "C" void fn_40_12C54(void*, Enemy* enemy) {
    float* thresholds = lbl_40_rodata_1B0;
    EnemyData* self = (EnemyData*)enemy;
    if (isCanAutoRemove__23emExternalValueAccesserFP5Enemy(
            self->accesser, enemy)) {
        Vec3f pos = getPos__23soExternalValueAccesserFP11StageObject(
            self->accesser);
        CameraControllerData* camera =
            (CameraControllerData*)getManager__15gfCameraManagerFv();
        Stage* stage = (Stage*)lbl_40_bss_15C;

        Vec3f cameraPos;
        cameraPos.m_x = camera->x;
        cameraPos.m_y = camera->y;
        cameraPos.m_z = camera->z;
        int specialCamera = 0;

        CameraControllerData* controller =
            getInstance__16CameraControllerFv();
        if (controller != 0 &&
            getInstance__16CameraControllerFv()->mode == 2) {
            specialCamera = 1;
        }

        if (specialCamera == 0) {
            if (static_cast<float>(fabs(static_cast<double>(
                    cameraPos.m_x - pos.m_x))) > thresholds[4] ||
                static_cast<float>(fabs(static_cast<double>(
                    cameraPos.m_y - pos.m_y))) > thresholds[5]) {
                self->state = 5;
            }
        }

        if (stage->fn_40_7134() != 0) {
            stPositions* positions = stage->m_deadPos;
            if (positions != 0) {
                Rect2D range;
                positions->getDeadRange(&range);

                char* positionData =
                    *(char**)((char*)lbl_27_bss_5668 + 0x78);
                Vec3f deadOffset;
                deadOffset.m_x = *(float*)(positionData + 0x20);
                deadOffset.m_y = *(float*)(positionData + 0x24);
                deadOffset.m_z = *(float*)(positionData + 0x28);

                if (range.m_left + deadOffset.m_x > pos.m_x ||
                    range.m_right + deadOffset.m_x < pos.m_x ||
                    range.m_down + deadOffset.m_y > pos.m_y ||
                    range.m_up + deadOffset.m_y < pos.m_y) {
                    self->state = 5;
                }

                if (isClipIn__23emExternalValueAccesserFP5Enemy(
                        self->accesser) == 0) {
                    self->timer += fn_8004E94C(g_GameGlobal);
                } else {
                    self->timer = thresholds[0];
                }

                if (self->timer > thresholds[6]) {
                    self->state = 5;
                }
            }
        }
    }
}
