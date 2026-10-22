#pragma force_active on
extern "C" {

void* getMsgData__5MuMsgFUlPPv(void* self, unsigned long index, void** size);
void getPrintIndexData__7MessageFPvUlPPcPUl(void* this_, unsigned long index, char** data, unsigned long* size);
void fn_800BF850(void* self, int id, char* str, int len, int flag);

void fn_800BFA8C(void* self, void* arg1, unsigned long arg2) {
    unsigned long sp10;
    unsigned long spC;
    char* sp8;

    if (*(int*)((char*)self + 0xFC) == 2) {
        if (arg1 == 0) {
            sp8 = (char*)getMsgData__5MuMsgFUlPPv(*(void**)((char*)self + 0x48), arg2, (void**)&spC);
        } else {
            getPrintIndexData__7MessageFPvUlPPcPUl(arg1, arg2, &sp8, &sp10);
            spC = sp10;
        }
        fn_800BF850(self, 4, sp8, (int)spC, 2);
    }
}

}
