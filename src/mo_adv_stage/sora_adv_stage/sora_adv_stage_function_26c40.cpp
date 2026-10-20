#pragma force_active on
extern "C" {
extern char lbl_40_data_788C[];
extern void* g_stTriggerMng;
bool isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(void*, void*, int);
char getPlayerNumber__10grYakumonoFP12grCollStatus(void*, void*);
void setTriggerFlag__12stTriggerMngFP13stTriggerData(void*, void*);
void fn_40_26C40(void*, void*, int, int);
}

void fn_40_26C40(void* ths, void* collStatus, int unused, int flag) {
    if (isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(ths, collStatus, (int)(unsigned long)lbl_40_data_788C)) {
        if (getPlayerNumber__10grYakumonoFP12grCollStatus(ths, collStatus) == 0) {
            if (flag) {
                void* ptr = *(void**)((char*)ths + 0x160);
                setTriggerFlag__12stTriggerMngFP13stTriggerData(g_stTriggerMng, (char*)ptr + 0x224);
            }
        }
    }
}
