#pragma force_active on
extern "C" void fn_800435E8(void* r3, void* r4, void* r5);

extern "C" void fn_80125E30(void* arg0) {
    fn_800435E8((char*)arg0 + 0x370, (char*)arg0 + 0x3e8, (char*)arg0 + 0x3ac);
}
