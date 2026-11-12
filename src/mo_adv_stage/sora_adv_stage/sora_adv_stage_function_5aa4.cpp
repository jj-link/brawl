#include <ft/ft_manager.h>
#include <so/so_external_value_accesser.h>
#include <gf/gf_camera.h>
#pragma force_active on
struct Owner {
    int pad[3];
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};
extern "C" {
extern const float lbl_40_rodata_2C[];
int getEntryId__9ftManagerFi(ftManager*, int);
Owner* getOwner__9ftManagerFi(ftManager*, int);
int fn_27_10A9DC(ftManager*, int);
int getFighterOperationStatus__9ftManagerFi(ftManager*, int);
void* getFighter__9ftManagerFii(ftManager*, int, int);
int isFighterActivate__9ftManagerFii(ftManager*, int, int);
int fn_27_10A848(ftManager*, int, int);
Vec3f getPos__23soExternalValueAccesserFP11StageObject(void*);
gfCameraManager* getManager__15gfCameraManagerFv();
int fn_80019C10(gfCameraManager*, float*);
int fn_27_10A78C(ftManager*, int);
void fn_27_112E0C(ftOwner*, int);
void fn_27_109F68(ftManager*, int);
void fn_27_109D50(ftManager*, int, int);
int fn_40_5AA4(void* self, int arg1) {
    Owner* owner;
    int i;
    int flag;
    int entryMain;
    int result;
    flag = 1;
    entryMain = getEntryId__9ftManagerFi(g_ftManager, 1);
    result = 0;
    i = 0;
    while (i < 4) {
        int entry = getEntryId__9ftManagerFi(g_ftManager, i);
        if (entry != -1) {
            owner = getOwner__9ftManagerFi(g_ftManager, entry);
            owner->vf3();
            owner->vf4();
        }
        i++;
    }
    if (entryMain != -1 && fn_27_10A9DC(g_ftManager, entryMain) != 0) {
        if (getFighterOperationStatus__9ftManagerFi(g_ftManager, entryMain) == 0) {
            result = 1;
        } else {
            if (arg1 == 0) {
                Vec3f pos;
                float cam[4];
                int success;
                void* fighter;
                int entry1 = getEntryId__9ftManagerFi(g_ftManager, 1);
                if (entry1 == -1) {
                    success = 0;
                } else {
                    fighter = getFighter__9ftManagerFii(g_ftManager, entry1, -1);
                    if (!fighter) {
                        success = 0;
                    } else if (!isFighterActivate__9ftManagerFii(g_ftManager, entry1, -1)) {
                        success = 0;
                    } else if (!fn_27_10A848(g_ftManager, entry1, -1)) {
                        success = 0;
                    } else {
                        pos = getPos__23soExternalValueAccesserFP11StageObject(fighter);
                        success = 1;
                    }
                }
                if (success) {
                    float x, y, z;
                    z = pos.m_z;
                    y = pos.m_y;
                    x = pos.m_x;
                    cam[0] = x;
                    cam[1] = y;
                    cam[2] = z;
                    cam[3] = lbl_40_rodata_2C[0];
                    gfCameraManager* mgr = getManager__15gfCameraManagerFv();
                    if (fn_80019C10(mgr, cam)) {
                        flag = 0;
                    }
                }
            }
            if (flag) {
                if (fn_27_10A78C(g_ftManager, entryMain)) {
                    fn_27_112E0C((ftOwner*)getOwner__9ftManagerFi(g_ftManager, entryMain), 1);
                }
                fn_27_109F68(g_ftManager, entryMain);
                fn_27_109D50(g_ftManager, entryMain, 3);
                result = 1;
            }
        }
    }
    return result;
}
}