#pragma force_active on
extern "C" void fn_27_247D98(void*);
extern "C" unsigned char lbl_27_data_4F920[];

extern "C" void* fn_27_250DB8(void* self) {
    fn_27_247D98(self);
    *reinterpret_cast<unsigned int*>(static_cast<char*>(self) + 0xCC) = 0;
    *reinterpret_cast<void**>(static_cast<char*>(self) + 0x3C) = lbl_27_data_4F920;
    return self;
}
