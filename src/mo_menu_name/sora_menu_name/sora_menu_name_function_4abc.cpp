#pragma force_active on

struct Self {
    char p0[0x70];
    void* obj70;
    char p1[0x154 - 0x74];
    void* f154;
    char p2[0x458 - 0x158];
    void* f458;
};

extern "C" {
extern float lbl_16_rodata_268;
extern float lbl_16_rodata_26C;

unsigned long fn_8006A470(char*);
void getPrintIndexData__7MessageFPvUlPPcPUl(
    void*, unsigned long, char**, unsigned long*);
void* memcpy(void*, const void*, unsigned long);
unsigned long strlen(const char*);
void fn_8006BCA8(char*, const void*);
void fn_800B92D8(void*, unsigned long, char*, unsigned long);
void setFrameVisible__8MuObjectFf(void*, float);

void fn_16_4ABC(
    Self* self, int index1, unsigned short name[16], int index2, int visible)
{
    char buffer[0x110];
    char nameBuf[8];
    unsigned long pos;
    unsigned long nameLen;
    char* data;
    unsigned long len;

    pos = fn_8006A470(buffer + 16);
    getPrintIndexData__7MessageFPvUlPPcPUl(
        self->f458, (unsigned long)index1, &data, &len);
    memcpy(buffer + 16 + pos, data, len);
    pos += len;

    fn_8006BCA8(nameBuf, name);
    nameLen = strlen(nameBuf);
    memcpy(buffer + 16 + pos, nameBuf, nameLen);
    pos += nameLen;

    getPrintIndexData__7MessageFPvUlPPcPUl(
        self->f458, (unsigned long)index2, &data, &len);
    memcpy(buffer + 16 + pos, data, len);
    pos += len;

    (buffer + 16)[pos] = 0;
    fn_800B92D8(self->f154, 6, buffer + 16, pos);

    float f = visible != 0 ? lbl_16_rodata_26C : lbl_16_rodata_268;
    setFrameVisible__8MuObjectFf(self->obj70, f);
}
}
