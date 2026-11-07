#include <mu/mu_msg.h>
#include <string.h>
#pragma force_active on
extern "C" {
extern char* lbl_805A01D8;
void* fn_800791FC(void*, unsigned int);
void fn_800B92D8(MuMsg*, unsigned long, char*, unsigned long);
const char* getMsgData__5MuMsgFUlPPv(MuMsg*, unsigned long, void**);
extern const float lbl_805A22F4;
extern const float lbl_805A22FC;
}
extern "C" void fn_800C1038(unsigned char* self, int index) {
    char buffer[1024];
    void* size;
    unsigned long len;
    const char* text;
    unsigned long pos;
    unsigned char* p = self + index * 16;
    bool flag = p[0x128] != 0;
    void* message;
    unsigned long id = *(unsigned long*)((char*)fn_800791FC(lbl_805A01D8, *(unsigned long*)(p + 0x124)) + 0x10);
    message = *(void**)(self + 0x348);
    text = getMsgData__5MuMsgFUlPPv(*(MuMsg**)(self + 0x5c), 0x79, &size);
    memcpy(buffer, text, (unsigned long)size);
    pos = (unsigned long)size;
    Message::getPrintIndexData(message, id, (char**)&text, &len);
    memcpy(buffer + pos, text, len);
    unsigned long end = pos + len;
    text = getMsgData__5MuMsgFUlPPv(*(MuMsg**)(self + 0x5c), 0x7a, &size);
    memcpy(buffer + end, text, (unsigned long)size);
    end += (unsigned long)size;
    buffer[end] = 0;
    fn_800B92D8(*(MuMsg**)(self + 0x5c), flag != 0, buffer, end + 1);
    if (flag) {
        (*(MuObject**)(self + 0x40))->setFrameMatCol(lbl_805A22F4);
        (*(MuMsg**)(self + 0x5c))->printIndex(2, 0x8b, 0);
        (*(MuMsg**)(self + 0x5c))->printIndex(3, 0x8c, 0);
    }
    (*(MuObject**)(self + 0x40))->setFrameVisible(lbl_805A22FC);
    if (flag) {
        float frame = lbl_805A22F4;
        (*(MuObject**)(self + 0x40))->setFrameMatCol(frame);
        self[0x108] = 1;
    }
}