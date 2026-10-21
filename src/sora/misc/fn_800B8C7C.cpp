#include <mu/mu_msg.h>
#pragma force_active on

void MuMsg::setMsgData(void* msgBinData) {
    m_msgData = msgBinData;
    *reinterpret_cast<unsigned char*>(this) |= 0x80;
}
