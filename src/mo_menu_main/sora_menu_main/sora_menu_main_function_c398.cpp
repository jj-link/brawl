#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
void* getInstance__16CameraControllerFv();
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_2_9A84(void*, u32, u32);
extern const char lbl_2_data_1360[];
extern const char lbl_2_data_718[];
}

extern "C" void fn_2_C398(u8* self) {
    char* cam = (char*)getInstance__16CameraControllerFv();
    char* p = (char*)__dynamic_cast(*(void**)(cam + 0x48), 4, lbl_2_data_1360,
                                    lbl_2_data_718, 0);
    fn_2_9A84(self, *(u32*)(self + 0x240), *(u32*)(self + 0x244));
    self[0x230] = 1;
    *(u32*)(self + 0x2fc) = *(u32*)(p + 0x40);
}
