#pragma force_active on

extern "C" {
void* getMsgData__5MuMsgFUlPPv(void* self, unsigned long index, void** size);
void* memcpy(void* dest, const void* src, unsigned long size);
int sprintf(char* str, const char* format, ...);
void fn_800B92D8(void* msg, unsigned long index, char* buffer, unsigned long len);
extern char lbl_40_data_17C6C[];
}

extern "C" void fn_40_41368(void* self, int arg1) {
    char buf[0x100];
    unsigned long size;
    unsigned long pos;
    unsigned long m1;
    int total = *(int*)((char*)self + 0xC10) - *(int*)((char*)self + 0xAB8);
    int c14 = *(int*)((char*)self + 0xC14);
    if (c14 > 0) {
        total += c14 - *(int*)((char*)self + 0xC08);
    }
    if (*(void**)((char*)self + 0x964) != 0) {
        unsigned long m0 = 2;
        if (arg1 != 0) {
            m0 = 0;
        }
        m1 = 3;
        if (arg1 != 0) {
            m1 = 1;
        }
        void* src = getMsgData__5MuMsgFUlPPv(*(void**)((char*)self + 0x964), m0, (void**)&size);
        memcpy(buf, src, size);
        pos = size;
        int len = sprintf(buf + pos, lbl_40_data_17C6C, total);
        size = len;
        pos += len;
        src = getMsgData__5MuMsgFUlPPv(*(void**)((char*)self + 0x964), m1, (void**)&size);
        memcpy(buf + pos, src, size);
        fn_800B92D8(*(void**)((char*)self + 0x964), 0, buf, pos + size);
    }
}
