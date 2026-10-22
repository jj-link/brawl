#pragma force_active on
typedef unsigned char u8;

extern "C" {
extern void* lbl_804233B8[];
void OSResumeThread(void*);
void free__13gfHeapManagerFPv(void*);
void __dt__8gfThreadFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_80037E64(void* self, int flag) {
    if (self) {
        u8* p = (u8*)self;
        *(void**)(p + 0x0) = lbl_804233B8;
        if (p[0x370] == 0) {
            OSResumeThread((char*)self + 8);
        }
        if (p[0x380]) {
            void* h = *(void**)(p + 0x378);
            if (h) {
                free__13gfHeapManagerFPv(h);
                *(void**)(p + 0x378) = 0;
            }
        }
        __dt__8gfThreadFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
