#pragma force_active on
extern "C" {
int getMsgData__5MuMsgFUlPPv(void* self, unsigned long idx, void** out);
void getPrintIndexData__7MessageFPvUlPPcPUl(void* self, void* idx, int* len, void** str);
void fn_800BF850(void* self, int id, int len, void* str, int flag);

void fn_800BFA04(void* self, void* msg, unsigned long idx) {
    void* tmp;
    void* str;
    int len;
    if (*(int*)((char*)self + 0xFC) == 1) {
        if (msg == 0) {
            len = getMsgData__5MuMsgFUlPPv(*(void**)((char*)self + 0x48), idx, &str);
        } else {
            getPrintIndexData__7MessageFPvUlPPcPUl(msg, (void*)idx, &len, &tmp);
            str = tmp;
        }
        fn_800BF850(self, 3, len, str, 2);
    }
}
}
