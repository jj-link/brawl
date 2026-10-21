#pragma force_active on
extern "C" {
void fn_801BE464(void *arg0, int arg1, unsigned char arg2, float arg3) {
    *(float *)((char *)arg0 + 0x9C) = arg3;
    *(int *)((char *)arg0 + 0xA4) = arg1;
    *(unsigned char *)((char *)arg0 + 0x34) = arg2;
    *(int *)((char *)arg0 + 0xA0) = 0;
}
}
