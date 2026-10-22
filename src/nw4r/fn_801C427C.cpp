#pragma force_active on

extern "C" void fn_801BC4C0(void* self);
extern "C" void fn_801C2F00(void* self, void* arg);
extern "C" void OSInitMutex(void* mutex);
extern "C" unsigned char lbl_80466A58[];
extern "C" unsigned char lbl_80466AC8[];

extern "C" void* fn_801C427C(void* arg0, int arg1) {
    unsigned char* p = (unsigned char*)arg0;
    fn_801BC4C0(arg0);
    *(void**)(p + 0x0) = lbl_80466A58;
    fn_801C2F00(p + 0xD8, lbl_80466A58);
    p[0x208] = 0;
    p[0x209] = 0;
    *(int*)(p + 0x1F4) = 0;
    *(int*)(p + 0x1F8) = arg1;
    *(int*)(p + 0x204) = 0;
    *(int*)(p + 0x20C) = 0;
    *(int*)(p + 0x414) = 0;
    *(int*)(p + 0x418) = 0;
    p[0x41C] = 0;
    *(void**)(p + 0x410) = lbl_80466AC8;
    *(int*)(p + 0x420) = 0;
    *(int*)(p + 0x424) = 0;
    *(int*)(p + 0x42C) = 0;
    *(int*)(p + 0x430) = 0;
    OSInitMutex(p + 0x434);
    return arg0;
}
