#pragma force_active on
typedef unsigned long u32;

struct Display {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void set(void*);
};

struct Pane {
    char pad[0x10];
    void* data;
};

struct Result {
    char pad[0x120];
    bool enabled;
    char pad2[7];
    u32 flags;
};

struct Menu {
    char pad[0x50];
    Display* display;
    char pad2[0x200 - 0x54];
    Pane* pane;
    char pad3[0x6068 - 0x204];
    void* resource;
    Result* result;
    void* message;
};

extern "C" {
u32 fn_8006A470(char*);
void getPrintIndexData__7MessageFPvUlPPcPUl(void*, u32, char**, u32*);
void fn_8006BCA8(char*, u32);
void* memcpy(void*, const void*, u32);
u32 strlen(const char*);
Result* fn_800BF048(int, char*, u32, void*, Display*,
                   int, int, int, int, int, int, int);
void fn_800BF97C(Result*, void*, int);
void fn_800BFA04(Result*, void*, int);

void fn_11_4270(Menu* self, u32 value) {
    char buffer[0x100];
    char number[0x18];
    char* text;
    u32 size;

    u32 pos = fn_8006A470(buffer);
    getPrintIndexData__7MessageFPvUlPPcPUl(self->message, 31, &text, &size);
    memcpy(buffer + pos, text, size);
    pos += size;

    fn_8006BCA8(number, value);
    u32 len = strlen(number);
    memcpy(buffer + pos, number, len);
    pos += len;

    getPrintIndexData__7MessageFPvUlPPcPUl(self->message, 32, &text, &size);
    memcpy(buffer + pos, text, size);
    pos += size;
    buffer[pos] = 0;

    self->display->set(self->pane->data);
    self->result = fn_800BF048(1, buffer, pos + 1, self->resource,
                              self->display, 23, 60, 42, 42, 0, 0, 240);
    self->result->enabled = true;
    self->result->flags = 0x2055;
    fn_800BF97C(self->result, self->message, 33);
    fn_800BFA04(self->result, self->message, 34);
}
}
