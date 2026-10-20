#pragma force_active on
typedef unsigned char u8;

extern "C" void remove__6utListFP10utListNode(void*, void*);
extern "C" void OSReport(const char*, ...);
extern char lbl_27_data_5B48[];

extern "C" int fn_27_57DC8(char* self) {
    void* node = *(void**)(self + 0xc);
    if (node != 0) {
        remove__6utListFP10utListNode(self + 0xc, node);
        return *(int*)((char*)node + 8);
    }
    OSReport(lbl_27_data_5B48);
    return -1;
}
