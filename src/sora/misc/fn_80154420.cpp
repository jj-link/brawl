#pragma force_active on
extern "C" void OSResumeThread(void*);
extern "C" void exit__6gfTaskFv(void*);
extern "C" void* __dt__8gfThreadFv(void*, short);
extern "C" void __dl__FPv(void*);
extern char lbl_804616D8[];

extern "C" void* fn_80154420(void* p, int flag)
{
    if (p != 0) {
        char* t = (char*)p;
        *(char**)(t + 0x000) = lbl_804616D8;
        *(char**)(t + 0x340) = lbl_804616D8 + 0xC;
        *(char**)(t + 0x344) = lbl_804616D8 + 0x18;
        *(char**)(t + 0x348) = lbl_804616D8 + 0x24;
        if (*(unsigned char*)(t + 0x34C) == 0) {
            *(signed char*)(t + 0x36C) = 1;
            OSResumeThread(t + 8);
        }
        exit__6gfTaskFv(*(void**)(t + 0x364));
        exit__6gfTaskFv(*(void**)(t + 0x368));
        __dt__8gfThreadFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
