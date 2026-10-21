#pragma force_active on

extern "C" {
int fn_800B5854(void*, int, int, int, int);
void fn_800B753C(void*, float);
void setUpdateRate__16gfModelAnimationFf(void*, float);
void setFrameVisible__8MuObjectFf(void*, float);
void printf__5MuMsgFUlPCce(void*, unsigned long, const char*, ...);
void printIndex__5MuMsgFUlUlPv(void*, unsigned long, unsigned long, void*);
int playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
void connect__19muWifiInterfaceTaskFb(void*, bool);

extern void* g_sndSystem;
extern void* g_muWifiInterfaceTask;
extern const float lbl_2_rodata_1750;
extern const float lbl_2_rodata_1760;
extern const char lbl_2_data_4BE8[];
}

extern "C" void fn_2_39258(void* self) {
    void* obj = *(void**)((char*)self + 0x48);
    fn_800B5854(obj, 1, 0x18, 0, 0);
    fn_800B753C(obj, lbl_2_rodata_1750);
    setUpdateRate__16gfModelAnimationFf(
        *(void**)((char*)obj + 0x14), lbl_2_rodata_1760);

    float frame = lbl_2_rodata_1750;
    setFrameVisible__8MuObjectFf(*(void**)((char*)self + 0x44), frame);

    printf__5MuMsgFUlPCce(
        *(void**)((char*)self + 0x74), 2, lbl_2_data_4BE8);
    printf__5MuMsgFUlPCce(
        *(void**)((char*)self + 0x74), 3, lbl_2_data_4BE8);
    printIndex__5MuMsgFUlUlPv(
        *(void**)((char*)self + 0x74), 1, 2, 0);

    *(int*)((char*)self + 0x144) =
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x204E, -1, 0, 0, -1);
    connect__19muWifiInterfaceTaskFb(g_muWifiInterfaceTask, true);
}
