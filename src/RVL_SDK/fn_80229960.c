#pragma force_active on
extern void fn_8022E928(const char* fmt, ...);
extern char lbl_8047E9AC[];
extern char lbl_804FB4A0[];

void fn_80229960(int arg0) {
    fn_8022E928(lbl_8047E9AC);
    (*(void (**)(int, char*))(lbl_804FB4A0 + 0x6F4))(arg0, lbl_804FB4A0);
}
