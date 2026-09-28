// Runtime.PPCEABI.H/Gecko_ExceptionPPC.c
// Provenance: structure follows doldecomp/melee src/Runtime/Gecko_ExceptionPPC.c (MIT),
// reconstructed from the Brawl target (build/RSBE01_02/asm/auto_03_803F1A78_text.s).

typedef struct __eti_init_info {
    void* eti_start;
    void* eti_end;
    void* code_start;
    unsigned long code_size;
} __eti_init_info;

typedef struct ProcessInfo {
    __eti_init_info* exception_info;
    char* TOC;
    int active;
} ProcessInfo;

static ProcessInfo fragmentinfo[1];

int __register_fragment(__eti_init_info* info, char* TOC) {
    ProcessInfo* f;
    int i;
    for (i = 0, f = fragmentinfo; i < 1; ++i, ++f) {
        if (f->active == 0) {
            f->exception_info = info;
            f->TOC = TOC;
            f->active = 1;
            return i;
        }
    }
    return -1;
}

void __unregister_fragment(int fragmentID) {
    if (fragmentID >= 0 && fragmentID < 1) {
        ProcessInfo* f = &fragmentinfo[fragmentID];
        f->exception_info = 0;
        f->TOC = 0;
        f->active = 0;
    }
}

int fn_803F1ADC(unsigned long addr, void* out) {
    ProcessInfo* pInfo;
    __eti_init_info* e;
    pInfo = fragmentinfo;
    if (pInfo->active != 0) {
        e = pInfo->exception_info;
        for (;;) {
            if (e->code_size == 0) {
                break;
            }
            if (addr >= (unsigned long)e->code_start &&
                addr < (unsigned long)e->code_start + e->code_size) {
                *(unsigned long*)((char*)out + 0x00) = (unsigned long)e->eti_start;
                *(unsigned long*)((char*)out + 0x04) = (unsigned long)e->eti_end;
                *(unsigned long*)((char*)out + 0x08) = 0;
                *(unsigned long*)((char*)out + 0x0C) = 0;
                *(unsigned long*)((char*)out + 0x10) = 0;
                *(unsigned long*)((char*)out + 0x14) = 0;
                *(unsigned long*)((char*)out + 0x18) = (unsigned long)pInfo->TOC;
                *(unsigned long*)((char*)out + 0x1C) = pInfo->active;
                return 1;
            }
            ++e;
        }
    }
    return 0;
}
