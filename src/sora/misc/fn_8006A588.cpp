#pragma force_active on

typedef unsigned char u8;
typedef unsigned long u32;

struct Buffer {
    char pad[0x4C];
    int count;
    u8* data;
};

class Message {
public:
    char pad[0x1D0];
    Buffer* buffer;

    void setDrawFlag(u32 p1, u32 p2);
};

void Message::setDrawFlag(u32 p1, u32 p2) {
    Buffer* b = this->buffer;
    b->data[b->count++] = 0x18;
    b = this->buffer;
    b->data[b->count++] = (p1 & 3) + ((p1 >> 2) & 0xC) + ((p1 >> 4) & 0x30);
    b = this->buffer;
    b->data[b->count++] = (p2 & 3) + ((p2 >> 2) & 0xC) + ((p2 >> 4) & 0x30);
}
