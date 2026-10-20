#pragma force_active on
struct MsgBits {
    unsigned int lo : 4;
    unsigned int hi : 2;
};

struct MsgData {
    MsgBits bits;
    unsigned int pad;
};

struct Msg {
    MsgData data[2];
};

extern "C" void fn_73_AC90(Msg *msg, int v)
{
    msg->data[1].bits.hi = v;
}
