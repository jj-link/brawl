#pragma force_active on
extern const double lbl_805A1A08;

struct Buffer {
    unsigned char pad[0x4c];
    int index;
    unsigned char* data;

    void write(unsigned char value) {
        data[index++] = value;
    }
};

class Message {
public:
    unsigned char pad[0x1d0];
    Buffer* buffer;
    void setFixedWidth(float value);
};

void Message::setFixedWidth(float value) {
    double d = lbl_805A1A08 * value;
    int v = (int)d;
    buffer->write(15);
    buffer->write((unsigned char)((short)v >> 8));
    buffer->write(v);
}