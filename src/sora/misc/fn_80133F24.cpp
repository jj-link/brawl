#pragma force_active on

struct Word {
    unsigned int type : 8;
    unsigned int rest : 24;
};

struct ByteFlags {
    unsigned char top : 1;
    unsigned char rest : 7;
};

class Ground {
public:
    unsigned char m_pad[8];
    Word unk8;
    unsigned char m_pad2[0x6d - 0xc];
    unsigned char unk6D;
    unsigned char m_pad3[0x75 - 0x6e];
    ByteFlags unk75;
};

extern "C" void fn_80133F24(void* arg0) {
    Ground* g = (Ground*)arg0;
    g->unk8.type = 2;
    if (!(g->unk6D & 0x08)) {
        g->unk75.top = 0;
    }
}
