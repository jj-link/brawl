#pragma force_active on
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern char lbl_9_data_0[];

extern "C" void fn_9_22D8(void* unused, char* buf, int a, unsigned int frames, int unused2, int mode) {
    char* base = lbl_9_data_0;
    if (mode != 0) {
        if (a != 0) {
            unsigned int hours = frames / 3600;
            unsigned int mins;
            unsigned int cents;
            if (hours >= 100) {
                hours = 99;
                mins = 59;
                cents = 99;
            } else {
                frames = frames - hours * 3600;
                mins = frames / 60;
                frames = frames - mins * 60;
                cents = frames * 100 / 60;
            }
            sprintf(buf, base + 0x18c, hours, mins, cents);
        } else {
            sprintf(buf, base + 0x19c);
        }
    } else {
        if (a != 0) {
            unsigned int v = (frames < 99999) ? frames : 99999;
            sprintf(buf, base + 0x180, v);
        } else {
            sprintf(buf, base + 0x1a8);
        }
    }
}
