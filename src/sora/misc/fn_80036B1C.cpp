#pragma force_active on
extern "C" {
void fn_80228154(int arg0);
}

struct Word0B0 {
    unsigned int hi : 4;
    unsigned int f : 4;
    unsigned int lo : 24;
};

class gfHomeMenu {
public:
    void start();
};

void gfHomeMenu::start() {
    unsigned char* self = (unsigned char*)this;
    int r4 = 0;
    if (((*(self + 0xB1) >> 4) & 1) != 0 || *(int*)(self + 0x9C) != 0) {
        r4 = 1;
    }
    if (r4 != 0) {
        fn_80228154(0);
        fn_80228154(1);
        fn_80228154(2);
        fn_80228154(3);
    }
    ((Word0B0*)(self + 0xB0))->f = 1;
}
