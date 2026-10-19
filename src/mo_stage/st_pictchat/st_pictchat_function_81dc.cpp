#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_73_81DC(void* self) {
    u8* base = (u8*)self;
    int state = base[0x150];
    if (state == 4) {
        goto body;
    }
    if (state >= 4) {
        return;
    }
    return;
body:
    {
        u8* p = *(u8**)(base + 0x298);
        *p = 0;
    }
}
