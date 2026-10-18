#pragma force_active on
extern "C" {
extern void* g_stTriggerMng;
extern void* g_ftManager;
extern char* lbl_27_bss_5668;
void setTriggerFlag__12stTriggerMngFP13stTriggerData(void*, void*);
void fn_40_50DC(void*, int);
void fn_27_2323A0(void*, void*);
void fn_27_10A1AC(void*, int);
}

extern "C" void fn_40_F628(char* self) {
    if (*(unsigned char*)(self + 0x1c) != 3) return;
    
    setTriggerFlag__12stTriggerMngFP13stTriggerData(g_stTriggerMng, (char*)*(char**)(self + 0x18) + 0x10);
    fn_40_50DC(*(void**)(self + 0x0c), 0xff);
    fn_27_2323A0(g_stTriggerMng, self);
    
    *(unsigned char*)(lbl_27_bss_5668 + 0xe9) = 1;
    *(unsigned char*)(lbl_27_bss_5668 + 0x19e) = 1;
    
    fn_27_10A1AC(g_ftManager, 1);
    
    *(unsigned char*)((char*)g_ftManager + 0x6c) |= 0x80;
}
