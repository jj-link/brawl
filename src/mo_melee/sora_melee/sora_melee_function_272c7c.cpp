#pragma force_active on
class grCollStatus;
class stTriggerData;

class grYakumono {
public:
    signed char getPlayerNumber(grCollStatus* collStatus);
};

class Ground : public grYakumono {
public:
    bool isCollisionStatusOwnerTask(grCollStatus* collStatus, int* arg);
};

class stTriggerMng {
public:
    void setTriggerFlag(stTriggerData* data);
};

extern stTriggerMng* g_stTriggerMng;
extern int lbl_27_data_580E0;

extern "C" void fn_27_272C7C(Ground* ths, grCollStatus* collStatus) {
    if (ths->isCollisionStatusOwnerTask(collStatus, &lbl_27_data_580E0)) {
        if (ths->getPlayerNumber(collStatus) == 0) {
            unsigned char* p = *(unsigned char**)((unsigned char*)ths + 0x150);
            g_stTriggerMng->setTriggerFlag((stTriggerData*)(p + 0x1e8));
        }
    }
}
