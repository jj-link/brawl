#pragma force_active on

extern "C" void fn_80228138(int arg0);

struct Word0B0 {
    unsigned int hi : 4;
    unsigned int f : 4;
    unsigned int lo : 24;
};

class gfHomeMenu {
public:
    void kill();
};

void gfHomeMenu::kill() {
    fn_80228138(0);
    fn_80228138(1);
    fn_80228138(2);
    fn_80228138(3);
    ((Word0B0*)((char*)this + 0xB0))->f = 2;
}
