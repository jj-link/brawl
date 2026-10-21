#pragma force_active on
typedef unsigned char u8;

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

    void setCallProjection(u8 value);
};

void Message::setCallProjection(u8 value) {
    buffer->put(0x1A);
    buffer->put(value);
}
