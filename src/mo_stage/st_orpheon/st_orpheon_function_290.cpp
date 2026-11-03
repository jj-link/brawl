#pragma force_active on
extern "C" {
extern char lbl_55_data_210[];
void releaseArchive__15stCommonGimmickFv(void*);
void __dt__Q28StSeUtil5SeSeqFv(void*, int);
void __dt__13grTenganEventFv(void*, int);
void __dt__7stMeleeFv(void*, int);
void __dl__FPv(void*);

void* fn_55_290(char* self, int flags) {
    if (self) {
        *(void**)(self + 0x3c) = lbl_55_data_210;
        releaseArchive__15stCommonGimmickFv(self);
        if (self + 0x688)
            __dt__Q28StSeUtil5SeSeqFv(self + 0x688, 0);
        if (self + 0x614)
            __dt__Q28StSeUtil5SeSeqFv(self + 0x614, 0);
        __dt__13grTenganEventFv(self + 0x534, -1);
        __dt__13grTenganEventFv(self + 0x488, -1);
        __dt__13grTenganEventFv(self + 0x3dc, -1);
        __dt__13grTenganEventFv(self + 0x330, -1);
        __dt__13grTenganEventFv(self + 0x284, -1);
        __dt__13grTenganEventFv(self + 0x1d8, -1);
        __dt__7stMeleeFv(self, 0);
        if (flags > 0)
            __dl__FPv(self);
    }
    return self;
}
}