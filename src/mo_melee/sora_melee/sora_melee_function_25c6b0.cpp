#pragma force_active on
extern "C" {
int isValid__14efScreenHandleCFv(void* self);
void fn_8005E3C8(void* screen, unsigned char* h, float f);
void setTriggerFlag__12stTriggerMngFP13stTriggerData(void* mng, void* data);
extern int g_efScreen;
extern void* g_stTriggerMng;

struct TriggerData {
    short a;
    unsigned char b;
    unsigned char c;
};

void fn_27_25C6B0(unsigned char* self) {
    unsigned char h;
    unsigned int v;
    TriggerData d;

    if (isValid__14efScreenHandleCFv(self + 0x52) != 0) {
        float f = (float)*(unsigned int*)(self + 0x68);
        h = self[0x52];
        fn_8005E3C8((void*)g_efScreen, &h, f);
        *(signed char*)(self + 0x52) = -1;
    }
    if (g_stTriggerMng != 0) {
        d.a = 1000;
        d.b = 1;
        d.c = 0;
        setTriggerFlag__12stTriggerMngFP13stTriggerData(g_stTriggerMng, &d);
    }
    *(int*)(self + 0x48) = 0xE;
}
}
