#include <cstring>
#include <types.h>
#pragma force_active on

class MuMsg {
public:
    const char* getMsgData(u32 msgIndex, void** msgLength);
};

class GameGlobal {
public:
    int getLanguage();
};
extern GameGlobal* g_GameGlobal;

struct MsgContainer {
    char _pad[0x5c4];
    MuMsg* m_msg;
};

extern "C" u32 fn_10_FDDC(MsgContainer* self, char* str, u32 pad, s32 index) {
    s32 msgIndex = -1;
    switch (index) {
        case 2:
            if (g_GameGlobal->getLanguage() == 1)
                msgIndex = 0x1a;
            else
                msgIndex = 0x19;
            break;
        case 3:
            msgIndex = 0x1b;
            break;
        case 5:
            msgIndex = 0x1c;
            break;
        case 6:
            msgIndex = 0x1d;
            break;
        case 4:
            msgIndex = 0x1e;
            break;
    }

    u32 strLen = strlen(str);
    if (msgIndex >= 0) {
        void* msgLength;
        const char* msgText = self->m_msg->getMsgData((u32)msgIndex, &msgLength);
        memcpy(str + strLen, msgText, (u32)msgLength);
        strLen += (u32)msgLength;
        str[strLen] = 0;
        strLen++;
    }
    return strLen;
}
