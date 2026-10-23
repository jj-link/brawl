#pragma force_active on
typedef struct Stream {
    char pad0[0x4C];
    int pos;
    unsigned char* data;
} Stream;

class Message {
public:
    char pad0[0x1D0];
    Stream* unk1D0;
    void setScale(float arg0, float arg1);
};

extern const float lbl_805A19F0;
extern const float lbl_805A19F4;
extern const float lbl_805A19F8;

void Message::setScale(float arg0, float arg1) {
    float f1;
    float f2;
    float fa;
    float fb;
    Stream* s;
    int a;
    int b;

    f1 = (arg0 > lbl_805A19F4) ? lbl_805A19F0 : arg0;
    f2 = (arg1 > lbl_805A19F4) ? lbl_805A19F0 : arg1;
    fa = lbl_805A19F8 * f1;
    fb = lbl_805A19F8 * f2;
    s = unk1D0;
    s->data[s->pos++] = 0xD;
    a = (int)fa;
    b = (int)fb;
    s = unk1D0;
    s->data[s->pos++] = a;
    s = unk1D0;
    s->data[s->pos++] = b;
}
