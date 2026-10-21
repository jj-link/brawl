#pragma force_active on

extern "C" {
extern char lbl_62_data_1F8[];
void __dl__FPv(void*);
void releaseArchive__15stCommonGimmickFv(void*);
void __dt__9gfArchiveFv(void*, int);
void __dt__7stMeleeFv(void*, int);

void* fn_62_258(void* self, int del) {
    if (self != 0) {
        int ptr = *(int*)((char*)self + 0x4D8);
        *(char**)((char*)self + 0x3C) = lbl_62_data_1F8;
        if (ptr != 0) {
            __dl__FPv((void*)ptr);
        }
        releaseArchive__15stCommonGimmickFv(self);
        __dt__9gfArchiveFv((char*)self + 0x9F8, -1);
        __dt__9gfArchiveFv((char*)self + 0x978, -1);
        __dt__9gfArchiveFv((char*)self + 0x8F8, -1);
        __dt__9gfArchiveFv((char*)self + 0x878, -1);
        __dt__9gfArchiveFv((char*)self + 0x7F8, -1);
        __dt__9gfArchiveFv((char*)self + 0x778, -1);
        __dt__9gfArchiveFv((char*)self + 0x6F8, -1);
        __dt__9gfArchiveFv((char*)self + 0x678, -1);
        __dt__9gfArchiveFv((char*)self + 0x5F8, -1);
        __dt__9gfArchiveFv((char*)self + 0x578, -1);
        __dt__9gfArchiveFv((char*)self + 0x4F8, -1);
        __dt__7stMeleeFv(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
