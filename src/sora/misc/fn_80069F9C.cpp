#pragma force_active on
struct Stream {
    char pad0[0x4C];
    int pos;
    unsigned char* data;
};
class Message {
public:
    char pad0[0x1D0];
    Stream* unk1D0;
    void setScale(float);
};
extern const float lbl_805A19F0;
extern const float lbl_805A19F4;
extern const float lbl_805A19F8;
void Message::setScale(float arg0) {
    float f1 = (arg0 > lbl_805A19F4) ? lbl_805A19F0 : arg0;
    float fa = lbl_805A19F8 * f1;
    Stream* s = unk1D0;
    s->data[s->pos++] = 0xD;
    int a = (int)fa;
    s = unk1D0;
    s->data[s->pos++] = a;
    s = unk1D0;
    s->data[s->pos++] = a;
}
