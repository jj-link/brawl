#pragma force_active on
extern "C" {
extern const char lbl_27_data_4EDDC[];
extern const char lbl_27_data_4EF40[];
extern void* lbl_27_data_4EDD8;
extern void* g_sndSystem;

void fn_27_241E30(void* self, const char* name);

void* fn_27_247D98(void* self) {
    char* p = (char*)self;
    char* snd;
    int cnt;

    fn_27_241E30(self, lbl_27_data_4EDDC);
    *(const void**)(p + 0x3C) = lbl_27_data_4EF40;
    *(int*)(p + 0x48) = 0;
    *(int*)(p + 0x4C) = 0;
    *(int*)(p + 0x50) = 0;
    *(int*)(p + 0x54) = 0;
    *(unsigned char*)(p + 0x74) = 0;
    *(unsigned char*)(p + 0x75) = 0;
    *(unsigned char*)(p + 0x76) = 0;
    snd = (char*)g_sndSystem;
    cnt = (unsigned short)(*(int*)(snd + 0x6E8) + 1);
    *(int*)(snd + 0x6E8) = cnt;
    *(int*)(p + 0xAC) = cnt;
    *(unsigned int*)(p + 0xB0) = 0xFF439EB2;
    *(void**)(p + 0xB4) = lbl_27_data_4EDD8;
    *(int*)(p + 0xB8) = 0;
    *(unsigned char*)(p + 0xBD) = 0;
    *(unsigned char*)(p + 0xBE) = 0;
    *(int*)(p + 0x58) = 0;
    *(int*)(p + 0x5C) = 0;
    *(int*)(p + 0x60) = 0;
    *(int*)(p + 0x64) = 0;
    *(int*)(p + 0x68) = 0;
    *(int*)(p + 0x6C) = 0;
    *(int*)(p + 0x70) = 0;
    return self;
}
}
