#pragma force_active on

extern "C" {
extern void* g_aiMgr;
extern char lbl_27_data_48598[];
unsigned long long fn_27_1F1CD0(void*, void*);
void* fn_27_20C6E8(void*, int);
void free__13gfHeapManagerFPv(void*, void*);
void __dt__7IpHumanFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_27_1F3520(void* p, int flag) {
    if (p != 0) {
        *(void**)((char*)p + 0x4) = lbl_27_data_48598;
        unsigned long long r = fn_27_1F1CD0(g_aiMgr, (char*)p + 0x42);
        if (*(unsigned short*)((char*)p + 0x3C) & 0x40) {
            void* h = *(void**)((char*)p + 0x38);
            if (h != 0) {
                free__13gfHeapManagerFPv(h, (void*)(unsigned int)r);
                *(void**)((char*)p + 0x38) = 0;
            }
            unsigned int f = *(unsigned short*)((char*)p + 0x3C);
            f &= ~0x40u;
            *(unsigned short*)((char*)p + 0x3C) = (unsigned short)f;
        }
        if (*(int*)((char*)p + 0x44) != 0) {
            fn_27_20C6E8(*(void**)((char*)p + 0x44), 1);
            *(int*)((char*)p + 0x44) = 0;
        }
        __dt__7IpHumanFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
