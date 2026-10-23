#pragma force_active on
typedef unsigned char u8;

struct Buffer {
    char pad[0x4C];
    int count;
    u8* data;
};

class Message {
public:
    char pad[0x1D0];
    Buffer* buffer;

    void setFace(u8 face);
};

void Message::setFace(u8 face) {
    Buffer* b = this->buffer;
    b->data[b->count++] = 2;
    b = this->buffer;
    b->data[b->count++] = face;
}
