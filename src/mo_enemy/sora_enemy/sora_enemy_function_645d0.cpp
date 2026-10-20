#pragma force_active on
typedef unsigned char u8;

extern "C" void Report__14wnemCommonProcFPCce(const char*, ...);
extern "C" void executeAnimCmd__10wnemSimpleFUl(void*, unsigned long);
extern "C" void RequestDeactive__10wnemSimpleFv(void*);
extern const char lbl_41_data_1C7EA[];
extern const float lbl_41_rodata_1188[];

extern "C" void fn_41_645D0(void* a) {
    u8 x = *reinterpret_cast<u8*>(static_cast<char*>(a) + 0x2214);
    *reinterpret_cast<u8*>(static_cast<char*>(a) + 0x2214) = 0;
    if (x) {
        Report__14wnemCommonProcFPCce(lbl_41_data_1C7EA);
        executeAnimCmd__10wnemSimpleFUl(a, 1);
        executeAnimCmd__10wnemSimpleFUl(a, 3);
        float f = lbl_41_rodata_1188[0];
        *reinterpret_cast<float*>(static_cast<char*>(a) + 0x2204) = f;
        *reinterpret_cast<float*>(static_cast<char*>(a) + 0x2200) = f;
        *reinterpret_cast<float*>(static_cast<char*>(a) + 0x21FC) = f;
        *reinterpret_cast<float*>(static_cast<char*>(a) + 0x21F8) = f;
        RequestDeactive__10wnemSimpleFv(a);
    }
}
