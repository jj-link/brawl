#pragma force_active on
struct Message;

struct MuMsg {
    char pad0[8];
    Message* unk8;
};

extern "C" void changeMsgBuf__7MessageFi(Message* self, int arg0);
extern "C" void fn_8006A8E8(Message* msg);

extern "C" void isEndDelayPrint__5MuMsgFUl(MuMsg* self, unsigned long arg0) {
    changeMsgBuf__7MessageFi(self->unk8, arg0);
    fn_8006A8E8(self->unk8);
}
