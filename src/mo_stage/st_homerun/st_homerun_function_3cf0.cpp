#pragma force_active on
extern "C" {
void OSReport(const char* msg, ...);
void playSE__9sndSystemF5SndIDiiii(void* self, int id, int a, int b, int c, int d);
extern void* g_GameGlobal;
extern void* g_sndSystem;
extern char lbl_88_data_840[];
}

extern "C" void fn_88_3CF0(char* self, unsigned int id, int kind, unsigned int val) {
    if (kind == 0x17) {
        if (id == *(unsigned int*)(self + 0x5e4)) {
            *(unsigned int*)(self + 0x5e4) = 0;
        } else if (id == *(unsigned int*)(self + 0x5e8)) {
            *(unsigned int*)(self + 0x5e8) = 0;
        } else if (id == *(unsigned int*)(self + 0x5ec)) {
            *(unsigned int*)(self + 0x5ec) = 0;
        }

        char* p = *(char**)((char*)g_GameGlobal + 0x44) + 0xc;
        if (*(unsigned short*)p < 0x100) {
            *(char*)(p + 0x202 + *(unsigned short*)p) = (char)kind;
            *(unsigned short*)(p + *(unsigned short*)p * 2 + 2) = val;
            OSReport(lbl_88_data_840, *(unsigned short*)p, (unsigned char)kind, (unsigned short)val);
            *(unsigned short*)p = *(unsigned short*)p + 1;
        }

        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x1EDC, 0, 0, 0, -1);
    }
}
