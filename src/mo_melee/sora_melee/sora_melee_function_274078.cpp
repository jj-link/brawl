#pragma force_active on
extern "C" void __ct__10grYakumonoFPCc(void* self, const char* name);
extern "C" char lbl_27_data_58920[];
extern "C" const float lbl_27_rodata_44D8;

class grGimmickWarpZone {
public:
    grGimmickWarpZone(const char* name);
};

grGimmickWarpZone::grGimmickWarpZone(const char* name) {
    __ct__10grYakumonoFPCc(this, name);
    float zero = lbl_27_rodata_44D8;
    char* self = reinterpret_cast<char*>(this);
    *reinterpret_cast<char**>(self + 0x3C) = lbl_27_data_58920;
    *reinterpret_cast<int*>(self + 0x150) = 0;
    *reinterpret_cast<unsigned char*>(self + 0x154) = 0;
    *reinterpret_cast<float*>(self + 0x158) = zero;
    *reinterpret_cast<unsigned char*>(self + 0x168) = 7;
    *reinterpret_cast<unsigned char*>(self + 0x169) = 0;
    *reinterpret_cast<int*>(self + 0x194) = 0;
    *reinterpret_cast<int*>(self + 0x198) = 0;
    *reinterpret_cast<float*>(self + 0x15C) = zero;
    *reinterpret_cast<float*>(self + 0x160) = zero;
    *reinterpret_cast<float*>(self + 0x164) = zero;
}
