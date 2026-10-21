#pragma force_active on

extern "C" void fn_802D7708(void* self, unsigned int arg1, void* arg2, void* arg3) {
    extern void* lbl_80487868[];
    unsigned char* p = (unsigned char*)self;
    *(unsigned short*)(p + 6) = 1;
    *(void**)(p) = (void*)lbl_80487868;
    unsigned int var_r0 = *(unsigned short*)((unsigned char*)arg3 + 0x92);
    unsigned int temp_r7 = *(unsigned short*)((unsigned char*)arg2 + 0x92);
    if (temp_r7 < var_r0)
        var_r0 = temp_r7;
    *(unsigned short*)(p + 0x14) = (unsigned short)var_r0;
    *(unsigned int*)(p + 0x08) = arg1;
    *(void**)(p + 0x0C) = arg2;
    *(void**)(p + 0x10) = arg3;
}
