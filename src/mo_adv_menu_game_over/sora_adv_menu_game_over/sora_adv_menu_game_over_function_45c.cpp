#pragma force_active on
extern "C" {
extern char lbl_8049E550[];
extern char lbl_33_data_2D0[];
extern char lbl_33_data_280[];
extern char lbl_8045C4BC[];
void addTail__6utListFP10utListNode(void* list, void* node);
void removeExist__6utListFP10utListNode(void* list, void* node);

void* fn_33_45C(void* self) {
    char* s = (char*)self;
    char* n = s + 4;
    char* L = lbl_8049E550;
    *(void**)(s + 0x0) = 0;
    *(void**)(s + 0xC) = 0;
    *(void**)(n + 0x0) = 0;
    *(void**)(n + 0x4) = 0;
    addTail__6utListFP10utListNode(L, n);
    *(void**)(n + 0xC) = lbl_33_data_2D0;
    *(void**)(n + 0x8) = L;
    *(void**)(s + 0x30) = lbl_8045C4BC;
    *(void**)(s + 0x10) = lbl_8045C4BC + 8;
    *(void**)(s + 0x1C) = 0;
    *(void**)(s + 0x14) = 0;
    *(void**)(s + 0x18) = 0;
    char* m = s + 0x14;
    addTail__6utListFP10utListNode(L, m);
    *(void**)(m + 0x8) = L;
    *(void**)(m + 0xC) = lbl_33_data_280;
    *(void**)(m + 0x10) = 0;
    *(char*)(m + 0x14) = 0;
    *(char*)(s + 0x2C) = 0;
    removeExist__6utListFP10utListNode(L, m);
    *(void**)(s + 0x1C) = 0;
    return self;
}
}
