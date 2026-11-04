#pragma force_active on
#include <ms/ms_message.h>

struct WindowSetting {
    unsigned int flags;
    float x, y, w, h;
    unsigned char color[4], edge[4];
    float width, edgeSize, space, f28, f2c, scaleX, scaleY, f38, f3c, f40, f44;
};
struct MuMsg {
    char pad[8];
    Message* message;
    WindowSetting* settings;
    void beginPrint(unsigned long);
};
extern "C" {
void fn_80069C7C(Message*, unsigned int, int);
void fn_80069D08(Message*, int);
void fn_8006A3A8(Message*, float, float);
void fn_8006A488(Message*, void*, float);
void fn_8006A170(Message*, void*);
void fn_8006A28C(Message*, void*);
void fn_8006A0B4(Message*, float);
void fn_8006A100(Message*, float);
void fn_8006A6A8(Message*, float, float, float, float);
extern int lbl_805A0178;
}
extern const float lbl_805A2210;
extern const float lbl_805A2224;
extern const float lbl_805A222C;

void MuMsg::beginPrint(unsigned long index) {
    WindowSetting* p = &this->settings[index];
    this->message->changeMsgBuf(index);
    this->message->clearMsgBuf();
    this->message->setWindow(p->x, p->y, p->w, p->h);
    if (p->flags >> 31) fn_80069C7C(this->message, 0xffff00ff, 8);
    switch ((p->flags >> 29) & 3) {
    case 0: this->message->setDrawFlag(1, 3); break;
    case 1: this->message->setDrawFlag(0, 3); break;
    case 2: this->message->setDrawFlag(2, 3); break;
    }
    switch ((p->flags >> 28) & 1) {
    case 0: this->message->setDrawFlag(0x100, 0x300); break;
    case 1: this->message->setDrawFlag(0, 0x300); break;
    }
    fn_8006A3A8(this->message, p->f28, lbl_805A222C);
    this->message->setScale(p->scaleX, p->scaleY);
    switch ((p->flags >> 26) & 3) {
    case 0: this->message->setFixedWidth(lbl_805A2224); fn_80069D08(this->message, 1); break;
    case 1: this->message->setFixedWidth(lbl_805A2224); break;
    case 2: this->message->setFixedWidth(p->width); break;
    }
    switch ((p->flags >> 22) & 7) {
    case 1: this->message->setFace(2); break;
    case 4: this->message->setFace(4); break;
    case 3: this->message->setFace(3); break;
    case 5: this->message->setFace(6); break;
    case 6: this->message->setFace(5); break;
    case 0:
    case 2:
    default: {
        Message* msg = this->message;
        if (lbl_805A0178) msg->setFace(8);
        else msg->setFace(1);
        break;
    }
    }
    if ((p->flags >> 25) & 1) fn_8006A488(this->message, p->edge, p->edgeSize);
    fn_8006A170(this->message, p->color);
    fn_8006A28C(this->message, p->color);
    if (p->f2c >= lbl_805A2210) fn_8006A0B4(this->message, p->f2c);
    fn_8006A100(this->message, p->space);
    if (p->f38 >= lbl_805A2210) fn_8006A6A8(this->message, p->f38, p->f3c, p->f40, p->f44);
}