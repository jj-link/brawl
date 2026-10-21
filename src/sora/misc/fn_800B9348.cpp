#pragma force_active on
struct Message;

struct MuMsg {
    char pad0[4];
    Message* unk4;
    char* getMsgData(unsigned long id, void** out);
};

extern "C" char* getPrintIndexData__7MessageFPvUlPPcPUl(Message*, void*, unsigned long, char**);

char* MuMsg::getMsgData(unsigned long id, void** out) {
    char* p;
    unsigned long n;
    getPrintIndexData__7MessageFPvUlPPcPUl(unk4, (void*)id, (unsigned long)&p, (char**)&n);
    *out = (void*)n;
    return p;
}
