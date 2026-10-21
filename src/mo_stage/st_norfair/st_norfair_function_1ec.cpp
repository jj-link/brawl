#pragma force_active on

extern "C" {
extern char lbl_54_data_1CC[];
void releaseArchive__15stCommonGimmickFv(void*);
void __dt__13grTenganEventFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__7stMeleeFv(void*, int);
void __dl__FPv(void*);
}

struct Resource {
    virtual ~Resource();
};

extern "C" void* fn_54_1EC(void* self, int flag) {
    if (self) {
        char* p = (char*)self;
        Resource* first = *(Resource**)(p + 0x828);
        *(void**)(p + 0x3C) = lbl_54_data_1CC;
        if (first) {
            delete first;
        }
        *(void**)(p + 0x828) = 0;

        Resource* second = *(Resource**)(p + 0x82C);
        if (second) {
            delete second;
        }
        *(void**)(p + 0x82C) = 0;

        releaseArchive__15stCommonGimmickFv(self);
        __dt__13grTenganEventFv(p + 0x6C8, -1);
        __dt__13grTenganEventFv(p + 0x61C, -1);
        __dt__13grTenganEventFv(p + 0x570, -1);
        __destroy_arr(p + 0x214, __dt__13grTenganEventFv, 0xAC, 5);
        __dt__7stMeleeFv(self, 0);

        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
