#pragma force_active on

extern "C" void fn_51_2838(void*, const char*);
extern "C" char lbl_51_data_1208[];
extern "C" const float lbl_51_rodata_70;

extern "C" void* fn_51_3BAC(void* self, const char* task) {
    fn_51_2838(self, task);
    float z = lbl_51_rodata_70;
    *(unsigned int*)((char*)self + 0x158) = 0;
    *(char**)((char*)self + 0x3C) = lbl_51_data_1208;
    *(unsigned int*)((char*)self + 0x15C) = 0;
    *(unsigned int*)((char*)self + 0x160) = 0;
    *(unsigned int*)((char*)self + 0x164) = 0;
    *(unsigned int*)((char*)self + 0x168) = 0;
    *(unsigned int*)((char*)self + 0x16C) = 0;
    *(float*)((char*)self + 0x170) = z;
    *(float*)((char*)self + 0x174) = z;
    *(float*)((char*)self + 0x178) = z;
    *(unsigned char*)((char*)self + 0x17C) = 0;
    *(unsigned int*)((char*)self + 0x180) = 0;
    *(unsigned int*)((char*)self + 0x184) = 0;
    *(unsigned int*)((char*)self + 0x188) = 0;
    *(unsigned int*)((char*)self + 0x18C) = 0;
    *(unsigned int*)((char*)self + 0x190) = 0;
    return self;
}
