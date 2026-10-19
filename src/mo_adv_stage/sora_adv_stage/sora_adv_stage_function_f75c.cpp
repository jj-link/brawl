#pragma force_active on
class stTriggerData;
class stTriggerMng {
public:
    bool getTriggerFlag(stTriggerData* data, bool b);
};

extern "C" {
    extern stTriggerMng* g_stTriggerMng;
    bool getTriggerFlag__12stTriggerMngFP13stTriggerDatab(stTriggerMng*, stTriggerData*, bool);

    void fn_40_F75C(void* self) {
        char* s = (char*)self;
        if (getTriggerFlag__12stTriggerMngFP13stTriggerDatab(
                g_stTriggerMng,
                (stTriggerData*)((char*)(*(void**)(s + 0x10)) + 0xc),
                false) == 1) {
            *(int*)(s + 0xc) = 3;
        } else {
            if (*(int*)(s + 0xc) == 0) {
                *(int*)(s + 0xc) = 1;
            }
        }
    }
}
