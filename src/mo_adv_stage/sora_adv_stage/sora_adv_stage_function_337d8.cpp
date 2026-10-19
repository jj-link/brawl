#pragma force_active on
struct Ground;
struct grCollStatus;

extern "C" {
extern char lbl_40_data_F738[];
extern void* g_stTriggerMng;
void fn_40_337D8(Ground* ths, grCollStatus* collStatus, int unused, int flag);
bool isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(Ground*, grCollStatus*, int);
void setTriggerFlag__12stTriggerMngFP13stTriggerData(void*, void*);
}

void fn_40_337D8(Ground* ths, grCollStatus* collStatus, int unused, int flag) {
    if (isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(ths, collStatus, (int)lbl_40_data_F738)) {
        if (flag) {
            char* p = *(char**)((char*)ths + 0x154);
            setTriggerFlag__12stTriggerMngFP13stTriggerData(g_stTriggerMng, p + 0x1e0);
        }
    }
}
