#pragma force_active on

extern "C" {
void update__9grGimmickFf(void* self, float deltaFrame);
void updateCallback__9grGimmickFUl(void* self, unsigned long arg);
extern void* g_GameGlobal;
extern const float lbl_40_rodata_838[4];
}

extern "C" void fn_40_3C188(void* self, float deltaFrame) {
    unsigned char* s = (unsigned char*)self;
    const float* k = lbl_40_rodata_838;

    update__9grGimmickFf(self, deltaFrame);
    updateCallback__9grGimmickFUl(self, 0);

    if (s[0x189] == 0 && s[0x188] == 1) {
        unsigned char* gg = (unsigned char*)g_GameGlobal;
        unsigned char* p = *(unsigned char**)(gg + 0x30);
        p[0x603] = 7;
        *(float*)(s + 0x18c) = k[1];
    }

    s[0x189] = s[0x188];

    if (*((unsigned char*)(*(char**)((char*)g_GameGlobal + 0x30)) + 0x603) == 0) {
        float f = *(float*)(s + 0x18c);
        if (f > k[0]) {
            *(float*)(s + 0x18c) = f - k[2];
            return;
        }
        s[0x188] = 0;
    }
}
