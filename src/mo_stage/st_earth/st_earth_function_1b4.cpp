#pragma force_active on
extern "C" {
extern unsigned char lbl_66_data_208[];
void fn_27_239F6C(void*);
void __dla__FPv(void*);
void __dl__FPv(void*);
void releaseArchive__15stCommonGimmickFv(void*);
void __dt__9gfArchiveFv(void*, int);
void __dt__7stMeleeFv(void*, int);

void* fn_66_1B4(void* self, int flag) {
    if (self) {
        char* p = (char*)self;
        *(void**)(p + 0x3C) = lbl_66_data_208;
        fn_27_239F6C(p + 0x260);
        void* block = *(void**)(p + 0x278);
        if (block) {
            if (block)
                __dla__FPv((char*)block - 0x10);
        }
        void* ptr = *(void**)(p + 0x284);
        if (ptr)
            __dl__FPv(ptr);
        releaseArchive__15stCommonGimmickFv(self);
        __dt__9gfArchiveFv(p + 0x308, -1);
        __dt__9gfArchiveFv(p + 0x288, -1);
        __dt__7stMeleeFv(self, 0);
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}
}
