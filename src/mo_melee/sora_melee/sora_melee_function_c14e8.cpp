#pragma force_active on
extern "C" void fn_27_C1140(void*);
extern "C" float lbl_27_rodata_EB8;

extern "C" void fn_27_C14E8(void* self) {
    fn_27_C1140(self);

    float value = lbl_27_rodata_EB8;
    *reinterpret_cast<unsigned char*>(static_cast<char*>(self) + 0x44) = 0;
    *reinterpret_cast<float*>(static_cast<char*>(self) + 0x40) = value;
    *reinterpret_cast<float*>(static_cast<char*>(self) + 0x3C) = value;
}
