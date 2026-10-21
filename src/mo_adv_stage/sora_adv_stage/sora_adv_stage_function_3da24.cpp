#pragma force_active on
extern "C" {
void __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
extern char lbl_40_data_179F8[];
extern char lbl_40_data_17A04[];
}

extern "C" void* fn_40_3DA24(void* self) {
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_40_data_179F8, 0x1f, 0xe, 6, true);
    *(char**)((char*)self + 0x3C) = lbl_40_data_17A04;
    *(int*)((char*)self + 0x40) = 0;
    *(int*)((char*)self + 0x44) = 0;
    *(int*)((char*)self + 0x48) = 0;
    *(int*)((char*)self + 0x4C) = 0;
    *(int*)((char*)self + 0x50) = 0;
    *(int*)((char*)self + 0x54) = 0;
    *(int*)((char*)self + 0x58) = 0;
    *(int*)((char*)self + 0x5C) = 8;
    *(int*)((char*)self + 0x60) = 0x280;
    *(int*)((char*)self + 0x64) = 0x1d0;
    *(int*)((char*)self + 0x68) = 0;
    return self;
}
