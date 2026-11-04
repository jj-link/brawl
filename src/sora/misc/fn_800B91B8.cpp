#include <mu/mu_msg.h>
#pragma force_active on

extern "C" void fn_8006B0C8(Message*, void*, u32);

bool MuMsg::printIndex(u32 msgIndex, u32 lineIndex, void* msgBinData) {
    if (msgBinData == NULL) {
        msgBinData = m_msgData;
        if (msgBinData == NULL) {
            return false;
        }
    }
    beginPrint(msgIndex);
    fn_8006B0C8(m_message, msgBinData, lineIndex);
    return true;
}
