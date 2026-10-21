#pragma force_active on
extern "C" {
void fn_18_11C4(void*);
extern unsigned char lbl_18_data_FA0[];
extern void* g_GameGlobal;
unsigned char fn_8004E810(void*);
}

extern "C" void* fn_18_2030(void* self, void* a2, void* a3, void* arg6,
                             void* arg7) {
    fn_18_11C4(self);
    *(void**)((char*)self + 0x668) = lbl_18_data_FA0;
    *(void**)((char*)self + 0x698) = arg7;
    *(unsigned char*)((char*)self + 0x6a9) = 1;
    *(unsigned short*)((char*)self + 0x640) = 7;
    *(void**)((char*)self + 0x69c) = arg6;
    *(unsigned char*)((char*)self + 0x6a0) = 1;
    *(unsigned char*)((char*)self + 0x6a1) = 1;
    *(unsigned char*)((char*)self + 0x6a2) = 1;
    *(unsigned char*)((char*)self + 0x6a3) = 1;
    *(unsigned char*)((char*)self + 0x6a4) = 1;
    *(unsigned char*)((char*)self + 0x6a5) = 1;
    *(unsigned char*)((char*)self + 0x6a6) = 1;
    *(unsigned char*)((char*)self + 0x6a7) = fn_8004E810(g_GameGlobal);
    return self;
}
