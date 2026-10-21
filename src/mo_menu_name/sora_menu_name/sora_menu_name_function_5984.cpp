#pragma force_active on
extern "C" {
int fn_800B5854(void*, int, int, int, int);
void fn_16_4BD8(void*, int);
extern float lbl_16_rodata_288;
extern const char lbl_16_data_36D0[];
void setFrameNode__8MuObjectFf(void*, float);
void setFrameMatCol__8MuObjectFf(void*, float);
void printf__5MuMsgFUlPCce(void*, unsigned long, const char*, ...);
}

extern "C" void fn_16_5984(void* self) {
    void* obj = *(void**)((char*)self + 0x70);
    fn_800B5854(obj, 1, 0x11, 0, 0);
    setFrameNode__8MuObjectFf(obj, lbl_16_rodata_288);
    setFrameMatCol__8MuObjectFf(obj, lbl_16_rodata_288);
    fn_16_4BD8(self, *(int*)((char*)self + 0x454));
    printf__5MuMsgFUlPCce(*(void**)((char*)self + 0x154), 6, lbl_16_data_36D0);
}
