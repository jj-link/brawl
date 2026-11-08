#pragma force_active on
extern "C" {
void fn_801BC360(void*);
void fn_801C0AB0(void*);
extern char lbl_80466DD0[];
}

extern "C" void* fn_801D3FD4(void* arg0) {
    char* self = (char*)arg0;
    fn_801BC360(arg0);
    *(int*)(self + 0x74) = 0;
    *(char**)(self + 0x78) = 0;
    *(int*)(self + 0x80) = 0;
    *(int*)(self + 0x84) = 0;
    *(char**)(self + 0x00) = lbl_80466DD0;
    *(char**)(self + 0x7C) = lbl_80466DD0 + 0x24;
    *(char**)(self + 0x88) = lbl_80466DD0 + 0x38;
    *(unsigned char*)(self + 0x8C) = 0;
    fn_801C0AB0(self + 0xB8);
    return arg0;
}
