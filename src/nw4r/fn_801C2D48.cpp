#pragma force_active on
extern "C" void OSCancelAlarm(void*);

extern "C" void fn_801C2D48(unsigned char* p) {
    if (p[0]) {
        OSCancelAlarm(p + 8);
        p[0] = 0;
    }
}
