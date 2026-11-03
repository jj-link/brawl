#pragma force_active on

extern "C" {
void* getMsgData__5MuMsgFUlPPv(void* self, unsigned long index, void** size);
void* memcpy(void* dest, const void* src, unsigned long size);
void* memset(void* dest, int c, unsigned long size);
unsigned long strlen(const char* s);
int sprintf(char* str, const char* format, ...);
void printf__5MuMsgFUlPCce(void* msg, unsigned long index, const char* fmt, ...);
void fn_800B92D8(void* msg, unsigned long index, char* buffer, unsigned long len);
extern char lbl_3_data_CB8[];
extern char lbl_3_data_CBC[];
}

extern "C" void fn_3_D55C(void* self) {
    char* p = (char*)self + 0x108;
    char* q = p;
    unsigned int i = 0;
    for (; i < *(unsigned int*)((char*)self + 0x300); i++) {
        fn_800B92D8(*(void**)((char*)self + 0x100), i + 6, q, strlen(p));
        p += 0x2c;
        q += 0x2c;
    }
    if (*(unsigned int*)((char*)self + 0x314) == 0xb) {
        printf__5MuMsgFUlPCce(*(void**)((char*)self + 0xfc), 0, lbl_3_data_CB8);
    } else {
        unsigned long size;
        char buffer[0x40];
        memset(buffer, 0, 0x40);
        void* data = getMsgData__5MuMsgFUlPPv(*(void**)((char*)self + 0xfc), 0, (void**)&size);
        memcpy(buffer, data, size);
        int len = sprintf(buffer, lbl_3_data_CBC, buffer, *(unsigned int*)((char*)self + 0x310) + 1);
        void* data2 = getMsgData__5MuMsgFUlPPv(*(void**)((char*)self + 0xfc), 1, (void**)&size);
        memcpy(buffer + len, data2, size);
        fn_800B92D8(*(void**)((char*)self + 0xfc), 0, buffer, len + size);
    }
}