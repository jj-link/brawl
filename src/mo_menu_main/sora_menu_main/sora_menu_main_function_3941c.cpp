#pragma force_active on

extern "C" {
int fn_800B5854(void*, int, int, int, int);
void fn_800B753C(void*, float);
void setUpdateRate__16gfModelAnimationFf(void*, float);
void setFrameVisible__8MuObjectFf(void*, float);
void printf__5MuMsgFUlPCce(void*, unsigned long, const char*, ...);
void printIndex__5MuMsgFUlUlPv(void*, unsigned long, unsigned long, void*);
void fn_2_38D14(char* self);
void fn_2_3950C(...);
void fn_800C9D70(void* task);

extern void* g_muWifiInterfaceTask;
extern const float lbl_2_rodata_1750;
extern const float lbl_2_rodata_1760;
extern const char lbl_2_data_4BE8[];
extern char lbl_2_data_4C28[];
}

extern "C" void fn_2_3941C(char* self) {
    void* obj = *(void**)(self + 0x48);
    fn_800B5854(obj, 5, 0x18, 0, 0);
    fn_800B753C(obj, lbl_2_rodata_1750);
    setUpdateRate__16gfModelAnimationFf(*(void**)((char*)obj + 0x14), lbl_2_rodata_1760);
    float frame = lbl_2_rodata_1750;
    setFrameVisible__8MuObjectFf(*(void**)(self + 0x44), frame);
    printf__5MuMsgFUlPCce(*(void**)(self + 0x74), 2, lbl_2_data_4BE8);
    printf__5MuMsgFUlPCce(*(void**)(self + 0x74), 3, lbl_2_data_4BE8);
    printIndex__5MuMsgFUlUlPv(*(void**)(self + 0x74), 1, 3, 0);
    if (*(int*)(self + 0x40) == 1) {
        fn_2_38D14(self);
    }
    fn_2_3950C(lbl_2_data_4C28);
    fn_800C9D70(g_muWifiInterfaceTask);
}
