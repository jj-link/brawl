#pragma force_active on

extern "C" {
void getPrintIndexData__7MessageFPvUlPPcPUl(void*, unsigned long, char**, unsigned long*);
void* memcpy(void*, const void*, unsigned long);
int sprintf(char*, const char*, ...);
void fn_800BF928(void*, const char*);
extern char lbl_8059E4E0;
}

struct Unknown {
    char pad[0x44];
    void* a;
    void* b;
    void* c;
};

extern "C" void fn_800FCF10(void* arg0, int arg1) {
    Unknown* self = (Unknown*)arg0;
    char buffer[136];
    unsigned long len;
    char* data;
    
    getPrintIndexData__7MessageFPvUlPPcPUl(self->c, 0x13, &data, &len);
    memcpy(buffer, data, len);
    len += sprintf(buffer + len, &lbl_8059E4E0, arg1);
    fn_800BF928(self->a, buffer);
}
