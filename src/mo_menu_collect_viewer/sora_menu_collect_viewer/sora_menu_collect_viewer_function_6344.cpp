#pragma force_active on

extern "C" {
extern char lbl_6_rodata_0[];

void setFrameNode__8MuObjectFf(void*, float);
void setFontColor__5MuMsgFUlUcUcUcUc(
    void*, unsigned long, unsigned char, unsigned char,
    unsigned char, unsigned char);
void printIndex__5MuMsgFUlUlPv(void*, unsigned long, unsigned long, void*);
}

struct Data {
    char pad0[0x10c];
    void* object;
    char pad1[0x1c7c - 0x110];
    void* msg;
};

struct Self {
    char pad[0x1ac];
    Data* data;
};

extern "C" void fn_6_6344(Self* self, int arg) {
    char* base = lbl_6_rodata_0;

    setFrameNode__8MuObjectFf(
        self->data->object,
        arg ? *(float*)(base + 0x590) : *(float*)(base + 0x1c4));

    int first, second;
    if (arg) {
        first = 0;
        second = 1;
    } else {
        first = 1;
        second = 0;
    }

    int offset = first * 3;
    unsigned char* colors = (unsigned char*)(base + 0x5bc);
    unsigned char* color = colors + offset;

    setFontColor__5MuMsgFUlUcUcUcUc(
        self->data->msg, 13, colors[offset], color[1], color[2], 255);
    printIndex__5MuMsgFUlUlPv(self->data->msg, 13, 1, 0);

    offset = second * 3;
    color = colors + offset;

    setFontColor__5MuMsgFUlUcUcUcUc(
        self->data->msg, 14, colors[offset], color[1], color[2], 255);
    printIndex__5MuMsgFUlUlPv(self->data->msg, 14, 2, 0);
}
