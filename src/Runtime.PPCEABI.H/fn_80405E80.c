#pragma force_active on
extern void OSEnableScheduler(void);
extern void TRKLoadContext(void* ctx, int size);

void TRKEXICallBack(int arg1, void* arg2) {
    OSEnableScheduler();
    TRKLoadContext(arg2, 0x500);
}
