#pragma force_active on

extern "C" {
extern void __dl__FPv(void*);
extern void releaseArchive__15stCommonGimmickFv(void*);
extern void __dt__13grTenganEventFv(void*, int);
extern void __dt__7stMeleeFv(void*, int);
extern unsigned char lbl_59_data_2E8[];
extern void* g_GameGlobal;

struct ByteFlags {
    unsigned char reserved : 7;
    unsigned char lowest : 1;
};

void* fn_59_270(void* self, int deleteFlag) {
    if (self != 0) {
        *(void**)((char*)self + 0x3C) = lbl_59_data_2E8;
        __dl__FPv(*(void**)((char*)self + 0x690));
        __dl__FPv(*(void**)((char*)self + 0x694));
        releaseArchive__15stCommonGimmickFv(self);

        unsigned char* flag = *(unsigned char**)((char*)g_GameGlobal + 8);
        ((ByteFlags*)(flag + 0xF))->lowest = 0;

        __dt__13grTenganEventFv((char*)self + 0x6E8, -1);
        __dt__13grTenganEventFv((char*)self + 0x5E4, -1);
        __dt__13grTenganEventFv((char*)self + 0x538, -1);
        __dt__13grTenganEventFv((char*)self + 0x48C, -1);
        __dt__13grTenganEventFv((char*)self + 0x3E0, -1);
        __dt__13grTenganEventFv((char*)self + 0x334, -1);
        __dt__13grTenganEventFv((char*)self + 0x288, -1);
        __dt__13grTenganEventFv((char*)self + 0x1DC, -1);
        __dt__7stMeleeFv(self, 0);

        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
