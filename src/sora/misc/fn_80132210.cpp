#pragma force_active on
extern "C" void fn_80041884(void*, void*, void*);

extern "C" void fn_80132210(void* arg0) {
    fn_80041884((char*)arg0 + 0x344, (char*)arg0 + 0x364, (char*)arg0 + 0x354);
}
