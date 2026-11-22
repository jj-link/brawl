#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

struct Display;

struct Result {
    char pad[0x120];
    bool enabled;
    char pad2[7];
    u32 flags;
};

struct Menu {
    char pad[0x6C];
    Display* display;
    char pad2[0x608 - 0x70];
    void* resource;
    Result* result;
    void* message;
    char pad3[0x648 - 0x614];
    int count;
};

extern "C" {
u32 fn_8006A470(char*);
void getPrintIndexData__7MessageFPvUlPPcPUl(void*, u32, char**, u32*);
void fn_8006BCA8(char*, int);
void* memcpy(void*, const void*, u32);
u32 strlen(const char*);
Result* fn_800BF048(int, char*, u32, void*, Display*, int, int, int, int, int, int, int);
void fn_800BF97C(Result*, void*, int);
void fn_800BFA04(Result*, void*, int);
void fn_10_B1CC(void*);
void fn_10_10ACC(void*, u8);
void fn_10_19EF0(void*, int);
void fn_10_1C57C(void*, int);
}

extern "C" void fn_10_B010(Menu* self, int value) {
    signed char* p;
    char buffer[0x88];
    char number[0x18];
    char* text;
    u32 size;

    u32 pos = fn_8006A470(buffer);
    getPrintIndexData__7MessageFPvUlPPcPUl(self->message, 31, &text, &size);
    memcpy(buffer + pos, text, size);
    pos += size;

    fn_8006BCA8(number, value);
    size = strlen(number);
    memcpy(buffer + pos, number, size);
    pos += size;

    getPrintIndexData__7MessageFPvUlPPcPUl(self->message, 32, &text, &size);
    memcpy(buffer + pos, text, size);
    pos += size;
    buffer[pos++] = 0;

    fn_10_B1CC(self);
    fn_10_10ACC(self, 0);
    self->result = fn_800BF048(1, buffer, pos, self->resource, self->display, 0x74, 60, 42, 42, 0, 0, 240);
    self->result->enabled = true;
    self->result->flags = 0x2055;

    p = (signed char*)self;
    for (pos = 0; (int)pos < self->count; pos++) {
        fn_10_19EF0(*(void**)(*(signed char**)(p + 0x44) + 0x1A8), 1);
        fn_10_1C57C(*(void**)(*(signed char**)(p + 0x44) + 0x1AC), 1);
        p += 4;
    }

    fn_800BF97C(self->result, self->message, 33);
    fn_800BFA04(self->result, self->message, 34);
}
