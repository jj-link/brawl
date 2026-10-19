#pragma force_active on
extern "C" {
extern void* g_stTriggerMng;
void setTriggerFlag__12stTriggerMngFP13stTriggerData(void*, void*);
}

extern "C" int fn_40_3D5E4(char* self, unsigned int id, unsigned char* out) {
    char* p = *(char**)(self + 0x1a0);
    if (*(unsigned int*)(p + 0x38) == id) {
        setTriggerFlag__12stTriggerMngFP13stTriggerData(g_stTriggerMng, p + 0x44);
        char* q = *(char**)(self + 0x1a0);
        *(unsigned short*)out = *(unsigned short*)(q + 0x44);
        out[2] = q[0x46];
        out[3] = q[0x47];
        return 1;
    }
    return 0;
}
