#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Buf {
    char pad[0x4C];
    int count;
    u8* data;

    void put(u8 value) {
        data[count++] = value;
    }
};

class Message {
public:
    char pad[0x1D0];
    Buf* buffer;

    void setColor(int color);
};

void Message::setColor(int color) {
    buffer->put(0x0C);
    buffer->put((u32)color >> 24);
    buffer->put(((u32)color >> 16) & 0xFF);
    buffer->put(((u32)color >> 8) & 0xFF);
    buffer->put(color);
}
