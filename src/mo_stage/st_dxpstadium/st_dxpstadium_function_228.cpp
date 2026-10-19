#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);
extern void releaseArchive__15stCommonGimmickFv(void*);
extern void __dt__13grTenganEventFv(void*, int);
extern void __dt__7stMeleeFv(void*, int);
extern unsigned char lbl_83_data_BC[];
extern void* g_GameGlobal;
struct ByteFlags { unsigned char reserved : 7; unsigned char lowest : 1; };

void* fn_83_228(void* self, int deleteFlag) {
    if (self != 0) {
        void* ptr = *(void**)((char*)self + 0x700);
        *(void**)((char*)self + 0x3C) = lbl_83_data_BC;
        if (ptr != 0) {
            __dl__FPv(ptr);
        }
        releaseArchive__15stCommonGimmickFv(self);
        unsigned char* flag = *(unsigned char**)((char*)g_GameGlobal + 8);
        ((ByteFlags*)(flag + 0xF))->lowest = 0;
        __dt__13grTenganEventFv((char*)self + 0x61C, -1);
        __dt__13grTenganEventFv((char*)self + 0x534, -1);
        __dt__13grTenganEventFv((char*)self + 0x488, -1);
        __dt__13grTenganEventFv((char*)self + 0x3DC, -1);
        __dt__13grTenganEventFv((char*)self + 0x330, -1);
        __dt__13grTenganEventFv((char*)self + 0x284, -1);
        __dt__13grTenganEventFv((char*)self + 0x1D8, -1);
        __dt__7stMeleeFv(self, 0);
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
