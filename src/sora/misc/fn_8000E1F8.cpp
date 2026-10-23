#pragma force_active on
typedef unsigned char u8;

class gfSceneRoot {
public:
    void setUseCopyFB(u8 arg0);
    char pad0[0x500];
    u8 copyFB : 8;
    char pad1[5];
    u8 copyFB2 : 8;
};

void gfSceneRoot::setUseCopyFB(u8 arg0) {
    this->copyFB = arg0;
    this->copyFB2 = arg0;
}
