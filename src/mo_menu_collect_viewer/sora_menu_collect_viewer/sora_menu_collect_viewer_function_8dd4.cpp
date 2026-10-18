#pragma force_active on
extern "C" {
unsigned long fn_8006A470(char*);
void getPrintIndexData__7MessageFPvUlPPcPUl(
    void*, unsigned long, char**, unsigned long*);
void* memcpy(void*, const void*, unsigned long);
int sprintf(char*, const char*, ...);
extern char lbl_6_data_6E0[];
void fn_800B92D8(void*, unsigned long, char*, unsigned long);
}

struct MessageHolder {
    char pad[4];
    void* data;
};

struct Viewer {
    char pad[0x74];
    MessageHolder* message;
};

extern "C" void fn_6_8DD4(
    Viewer* self, unsigned long a, unsigned long b)
{
    char buffer[256];
    char number[24];
    char* data;
    unsigned long size;

    unsigned long pos = fn_8006A470(buffer);
    getPrintIndexData__7MessageFPvUlPPcPUl(
        self->message->data, 1, &data, &size);
    memcpy(buffer + pos, data, size);
    pos += size;

    if (a > 99)
        a = 99;

    int len = sprintf(number, lbl_6_data_6E0, a);
    memcpy(buffer + pos, number, len);
    pos += len;

    getPrintIndexData__7MessageFPvUlPPcPUl(
        self->message->data, 2, &data, &size);
    memcpy(buffer + pos, data, size);
    pos += size;

    if (b > 99)
        b = 99;

    len = sprintf(number, lbl_6_data_6E0, b);
    memcpy(buffer + pos, number, len);
    pos += len;

    getPrintIndexData__7MessageFPvUlPPcPUl(
        self->message->data, 3, &data, &size);
    memcpy(buffer + pos, data, size);
    pos += size;

    buffer[pos] = 0;
    fn_800B92D8(self->message, 1, buffer, pos);
}
