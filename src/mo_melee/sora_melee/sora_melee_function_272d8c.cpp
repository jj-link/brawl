#pragma force_active on
typedef unsigned int u32;

extern "C" void __ct__10grYakumonoFPCc(void* self, const char* name);
extern "C" char lbl_27_data_58394[];

extern "C" void* fn_27_272D8C(void* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    *(char**)((char*)self + 0x3C) = lbl_27_data_58394;
    *(u32*)((char*)self + 0x150) = 0;
    *(u32*)((char*)self + 0xE4) = 0xe;
    return self;
}
