#pragma force_active on
extern "C" {
void* getInstance__16CameraControllerFv();
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_40_data_1590[];
extern const char lbl_40_data_15D8[];
void fn_40_56B8(void* unused, float* src);
}

struct Flags8 {
    unsigned int hi : 8;
    unsigned int rest : 24;
};

extern "C" void fn_40_56B8(void* unused, float* src) {
    char* cam = (char*)getInstance__16CameraControllerFv();
    char* p = (char*)__dynamic_cast(*(void**)(cam + 0x48), 4, lbl_40_data_1590, lbl_40_data_15D8, 0);
    if (p) {
        *(float*)(p + 0xf8) = src[0];
        *(float*)(p + 0xfc) = src[1];
        Flags8* f = (Flags8*)(p + 8);
        f->hi = 2;
    }
}
