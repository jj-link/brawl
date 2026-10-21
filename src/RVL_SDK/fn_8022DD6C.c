#pragma force_active on
extern void fn_8022E928(const char* fmt, ...);
extern void OSReport(const char* fmt, ...);
extern const char lbl_8047F4F0[];
extern const char lbl_8047F50C[];

void fn_8022DD6C(unsigned int arg0) {
    fn_8022E928(lbl_8047F4F0);
    if (arg0 == 2) {
        OSReport(lbl_8047F50C);
    }
}
