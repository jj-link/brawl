#pragma force_active on
extern "C" {
extern void* g_stTriggerMng;
void setTriggerFlag__12stTriggerMngFP13stTriggerData(void*, void*);
}

extern "C" int fn_40_F8E0(char* self, unsigned int id, unsigned char* out) {
    char* p = *(char**)(self + 0x10);
    if (id == *(unsigned int*)(p + 0x8)) {
        setTriggerFlag__12stTriggerMngFP13stTriggerData(g_stTriggerMng, p + 0xc);
        char* q = *(char**)(self + 0x10);
        *(unsigned short*)out = *(unsigned short*)(q + 0xc);
        out[2] = q[0xe];
        out[3] = q[0xf];
        return 1;
    }
    return 0;
}
