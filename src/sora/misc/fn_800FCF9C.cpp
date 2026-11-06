#pragma force_active on
typedef unsigned long u32;

struct Result {
    char pad[0x120];
    bool enabled;
    char pad2[7];
    u32 flags;
};

struct Ctx {
    char pad0[0x0C];
    char resource[0x08];
    void* display;
    char pad1[0x44 - 0x18];
    Result* result;
    char pad2[0x4C - 0x48];
    void* message;
};

extern "C" {
u32 fn_8006A470(char*);
void getPrintIndexData__7MessageFPvUlPPcPUl(void*, u32, char**, u32*);
void fn_8006BCA8(char*, u32);
void* memcpy(void*, const void*, u32);
u32 strlen(const char*);
Result* fn_800BF048(int, char*, u32, void*, void*,
                    int, int, int, int, int, int, int);
void fn_800BF97C(Result*, void*, int);
void fn_800BFA04(Result*, void*, int);
}

extern "C" void fn_800FCF9C(void* arg0, u32 arg1) {
    Ctx* self = (Ctx*)arg0;
    char buffer[0x100];
    char number[0x18];
    char* text;
    u32 size;
    u32 pos;
    u32 len;

    pos = fn_8006A470(buffer);
    getPrintIndexData__7MessageFPvUlPPcPUl(self->message, 0x1F, &text, &size);
    memcpy(buffer + pos, text, size);
    pos += size;

    fn_8006BCA8(number, arg1);
    len = strlen(number);
    memcpy(buffer + pos, number, len);
    pos += len;

    getPrintIndexData__7MessageFPvUlPPcPUl(self->message, 0x20, &text, &size);
    memcpy(buffer + pos, text, size);
    pos += size;
    buffer[pos] = 0;

    self->result = fn_800BF048(1, buffer, pos + 1, self->resource, self->display,
                               0x40, 0x3C, 0x28, 0x2A, 1, 1, 0xF0);
    self->result->enabled = true;
    self->result->flags = 0x2055;
    fn_800BF97C(self->result, self->message, 0x21);
    fn_800BFA04(self->result, self->message, 0x22);
}
