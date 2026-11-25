#pragma force_active on

extern "C" {
void fn_800B7184(void*, char*, unsigned long, void*);
void fn_800B6EBC(void*, float*);
void* fn_800AE578(void*, unsigned short);
void* fn_8018D4D0(void*, unsigned long);
void fn_800B92D8(void*, unsigned long, char*, unsigned long);
void* getMsgData__5MuMsgFUlPPv(void*, unsigned long, void**);
void getPrintIndexData__7MessageFPvUlPPcPUl(void*, unsigned long, char**, unsigned long*);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
void* memcpy(void*, const void*, unsigned long);
void setFrameVisible__8MuObjectFf(void*, float);
extern char lbl_80456F4C[];
extern char lbl_8059E100;
extern const float lbl_805A22F0;
extern const float lbl_805A22F4;
}

extern "C" void fn_800C0E9C(unsigned char* self, int index)
{
    char buffer[0x400];
    float vec[3];
    void* size;
    unsigned long len;
    char* text;
    unsigned long pos;
    void* msgbin;
    unsigned short id;
    unsigned long msgid;
    unsigned long end;
    void* obj;
    unsigned char* p;
    void* model;
    unsigned char* d;
    unsigned short sy;
    unsigned short sx;

    id = *(unsigned short*)(self + index * 16 + 0x124);
    obj = *(void**)(self + 0x4c);
    p = self + index * 8;
    model = *(void**)(self + 0x54);

    fn_800B7184(obj, lbl_80456F4C, 0, p + 0x2c8);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(model, *(void**)((char*)obj + 0x10), &lbl_8059E100);

    d = (unsigned char*)fn_8018D4D0(p + 0x2c8, 0);
    sy = *(unsigned short*)(d + 0x1e);
    sx = *(unsigned short*)(d + 0x1c);
    float fy = lbl_805A22F0 * (float)sy;
    float fx = lbl_805A22F0 * (float)sx;
    vec[1] = fy;
    vec[0] = fx;
    vec[2] = lbl_805A22F4;
    fn_800B6EBC(obj, vec);

    msgid = *(unsigned long*)((char*)fn_800AE578(*(void**)(self + 0x2b8), id) + 0xc);
    msgbin = *(void**)(self + 0x2c0);

    text = (char*)getMsgData__5MuMsgFUlPPv(*(void**)(self + 0x5c), 0x77, &size);
    memcpy(buffer, text, (unsigned long)size);
    pos = (unsigned long)size;

    getPrintIndexData__7MessageFPvUlPPcPUl(msgbin, msgid, &text, &len);
    memcpy(buffer + pos, text, len);
    end = pos + len;

    text = (char*)getMsgData__5MuMsgFUlPPv(*(void**)(self + 0x5c), 0x78, &size);
    memcpy(buffer + end, text, (unsigned long)size);
    end += (unsigned long)size;

    buffer[end] = 0;
    fn_800B92D8(*(void**)(self + 0x5c), 0, buffer, end + 1);
    setFrameVisible__8MuObjectFf(*(void**)(self + 0x40), lbl_805A22F4);
}
