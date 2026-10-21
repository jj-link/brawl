#pragma force_active on
extern void fn_8022E928(const char* fmt, ...);
extern char lbl_8047E9BC[];
extern char lbl_804FB4A0[];

void fn_802299B0(void* arg0) {
    fn_8022E928(lbl_8047E9BC);
    ((void (*)(void*))(*(void**)(lbl_804FB4A0 + 0x6F8)))(arg0);
}
