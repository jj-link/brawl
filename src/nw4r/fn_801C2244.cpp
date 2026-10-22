#pragma force_active on
extern "C" {
void OSCreateAlarm(void*);
void fn_801D6E14(void*, void*);

void* fn_801C2244(void* p) {
    char* o = (char*)p;
    o[0] = 0;
    o[1] = 0;
    o[2] = 0;
    o[3] = 0;
    o[4] = 0;
    o[5] = 0;
    o[6] = 0;
    *(int*)(o + 0x0C) = 0;
    *(int*)(o + 0x10) = 0;
    *(int*)(o + 0x14) = 0;
    *(int*)(o + 0x3C) = 0;
    OSCreateAlarm(o + 0x40);
    fn_801D6E14(o + 0x40, p);
    OSCreateAlarm(o + 0x70);
    fn_801D6E14(o + 0x70, p);
    return p;
}
}
