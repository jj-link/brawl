#pragma force_active on
extern "C" {
extern void* g_stTriggerMng;
void setTriggerFlag__12stTriggerMngFP13stTriggerData(void*, void*);
void fn_40_533C(void*);
void fn_27_2323A0(void*, void*);
}

extern "C" void fn_40_F448(char* self) {
    if (*(unsigned char*)(self + 0x1c) != 3)
        return;

    setTriggerFlag__12stTriggerMngFP13stTriggerData(g_stTriggerMng,
                                                   *(char**)(self + 0x18) + 8);
    fn_40_533C(*(void**)(self + 0x0c));
    fn_27_2323A0(g_stTriggerMng, self);
    *(unsigned char*)(self + 0x1c) = 4;
}
