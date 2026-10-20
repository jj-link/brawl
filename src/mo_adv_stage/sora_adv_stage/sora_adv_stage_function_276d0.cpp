#pragma force_active on
extern "C" {
extern char lbl_40_data_7DF8[];
extern void* g_stTriggerMng;
extern const float lbl_40_rodata_3F8;
bool isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(void*, void*, int);
void setTriggerFlag__12stTriggerMngFP13stTriggerData(void*, void*);
void fn_40_276D0(void*, void*, int, int);
}

void fn_40_276D0(void* ths, void* collStatus, int unused, int flag) {
    if (isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(ths, collStatus, (int)(unsigned long)lbl_40_data_7DF8)) {
        if (flag) {
            char* p = (char*)ths;
            char* ptr = *(char**)(p + 0x14c);
            setTriggerFlag__12stTriggerMngFP13stTriggerData(g_stTriggerMng, ptr + 0x1a0);
            *(char*)(p + 0x150) = 1;
            *(float*)(p + 0x154) = lbl_40_rodata_3F8;
        }
    }
}
