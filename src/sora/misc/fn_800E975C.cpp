#include <ms/ms_message.h>
#pragma force_active on

extern "C" void fn_80069D08(Message*, unsigned char);
extern "C" void fn_80069EDC(Message*, const void*, unsigned int);
extern "C" void fn_8006A31C(Message*, unsigned int);

extern "C" void fn_800E975C(void* self, Message* msg, const void* data, unsigned int size, const float* pos, int flag, float scale) {
    msg->changeMsgBuf(-1);
    msg->clearMsgBuf();
    msg->setCallProjection(0);
    float x = pos[0];
    float y = pos[1];
    msg->setWindow(x, y - 16.0f, 128.0f + x, 16.0f + y);
    msg->setFixedWidth(-1.0f);
    if (flag) {
        msg->setDrawFlag(2, 3);
    } else {
        msg->setDrawFlag(0, 0x303);
    }
    fn_80069D08(msg, 1);
    msg->setScale(scale);
    msg->setColor(-1);
    fn_8006A31C(msg, -1);
    fn_80069EDC(msg, data, size);
    msg->printMsgBuf((FontData::FONT_RESOURCE)9);
}