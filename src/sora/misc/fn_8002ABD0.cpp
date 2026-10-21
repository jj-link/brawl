#pragma force_active on
extern "C" void fn_802162A4(int, int);
extern "C" void fn_8021A558(int, int);

class gfPadSystem {
public:
    void pauseNotify();
};

void gfPadSystem::pauseNotify() {
    int i;
    i = 0;
    do {
        fn_802162A4(i, 0);
        i++;
    } while (i < 4);
    i = 0;
    do {
        fn_8021A558(i, 0);
        i++;
    } while (i < 4);
}
