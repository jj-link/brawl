#pragma force_active on
#include <stddef.h>

extern "C" {

void* getMsgData__5MuMsgFUlPPv(void* self, unsigned long index, void** size);
void getPrintIndexData__7MessageFPvUlPPcPUl(void* self, unsigned long index, char** data, unsigned long* size);
void fn_800BF850(void* self, int id, const char* str, int len, int flag);

void fn_800BF97C(void* self, void* arg1, unsigned long arg2) {
    unsigned long tmp;
    unsigned long size;
    char* data;
    
    if (*(int*)((char*)self + 0xfc) == 1) {
        if (arg1 == NULL) {
            data = (char*)getMsgData__5MuMsgFUlPPv(*(void**)((char*)self + 0x48), arg2, (void**)&size);
        } else {
            getPrintIndexData__7MessageFPvUlPPcPUl(arg1, arg2, &data, &tmp);
            size = tmp;
        }
        fn_800BF850(self, 2, data, (int)size, 2);
    }
}

}
