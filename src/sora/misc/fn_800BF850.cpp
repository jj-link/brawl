#pragma force_active on
extern void* g_GameGlobal;

extern "C" {
int getLanguage__10GameGlobalFv(void* self);
void setFontColor__5MuMsgFUlUcUcUcUc(void* self, unsigned long id, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
int fn_8006C2EC(int, int, int, char*);
void fn_800B92D8(void* msg, unsigned long id, char* buf, int len);

void fn_800BF850(char* self, unsigned long id, int a, int b, int c) {
    char buf[0x3F8];
    int len;
    unsigned char col;
    if (getLanguage__10GameGlobalFv(g_GameGlobal) == 0) {
        col = (c == 2) ? 0 : 0x53;
    } else {
        col = (c == 2) ? 0 : 0x20;
    }
    len = fn_8006C2EC(a, b, 0xFFFF, buf);
    setFontColor__5MuMsgFUlUcUcUcUc(*(void**)(self + 0x48), id, col, col, col, 0xFF);
    fn_800B92D8(*(void**)(self + 0x48), id, buf, len);
}
}
