#pragma force_active on
typedef unsigned int u32;

extern "C" {
void fn_12_588(void* self, int value);
int sprintf(char* s, const char* fmt, ...);
void* getMsgData__5MuMsgFUlPPv(void* self, u32 index, void** size);
void* memcpy(void* dest, const void* src, u32 size);
void fn_800B92D8(void* msg, u32 index, char* buffer, u32 len);
void fn_80074ECC(void* snd, u32 flags, float f1, float f2);
void playBGM__9sndSystemFiUlb(void* self, u32 id, u32 param, u32 flag);
extern void* g_sndSystem;
extern const char lbl_12_data_24[];
extern const float lbl_12_rodata_60;
}

extern "C" void fn_12_1068(char* self) {
    char buf[0x108];
    fn_12_588(self, 6);
    if (*(int*)(self + 0x6c) > 0) {
        u32 size;
        int len = sprintf(buf, lbl_12_data_24, *(int*)(self + 0x6c));
        void* data = getMsgData__5MuMsgFUlPPv(*(void**)(self + 0x50), 0, (void**)&size);
        memcpy(buf + len, data, size);
        buf[len + size] = 0;
        fn_800B92D8(*(void**)(self + 0x50), 3, buf, len + size + 1);
    }
    fn_80074ECC(g_sndSystem, 0x2000, lbl_12_rodata_60, lbl_12_rodata_60);
    playBGM__9sndSystemFiUlb(g_sndSystem, 0x2864, 0, 1);
}