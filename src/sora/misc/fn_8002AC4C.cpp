#pragma force_active on
extern int lbl_805A0044;

class gfPadSystem {
public:
    void setConnectCallback(int arg);
};

void gfPadSystem::setConnectCallback(int arg) {
    lbl_805A0044 = arg;
}
