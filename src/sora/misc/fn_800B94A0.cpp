#pragma force_active on

struct MuMsgElem {
    char pad[0x24];
    float hSpace;
    char pad2[0x20];
};

class MuMsg {
public:
    char pad[0xC];
    MuMsgElem* elems;
    void setHSpace(unsigned long index, float value);
};

void MuMsg::setHSpace(unsigned long index, float value)
{
    elems[index].hSpace = value;
}
