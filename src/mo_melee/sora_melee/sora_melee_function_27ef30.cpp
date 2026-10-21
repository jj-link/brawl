#pragma force_active on
struct ftManager;
struct IfMngr;

struct StubObj {
    char pad0[0x2c];
    void* m_2c;
    char pad1[0x34 - 0x30];
    unsigned char m_34;
    char pad2[0x3c - 0x35];
    int m_3c;
};

extern ftManager* g_ftManager;
extern IfMngr* g_IfMngr;

extern "C" void fn_27_27D318(StubObj* self, int entryId, void* unused);
extern "C" void fn_800DCE54(IfMngr*, int);
extern "C" int getPlayerNo__9ftManagerFi(ftManager*, int);

extern "C" void fn_27_27EF30(StubObj* self, int entryId, void* unused, float* src) {
    fn_27_27D318(self, entryId, unused);
    if ((self->m_34 >> 7) & 1) {
        if (self->m_2c != 0) {
            if (getPlayerNo__9ftManagerFi(g_ftManager, entryId) != 0) {
                int value = (int)src[1];
                self->m_3c = value;
                if (g_IfMngr != 0) {
                    fn_800DCE54(g_IfMngr, value);
                }
            }
        }
    }
}
