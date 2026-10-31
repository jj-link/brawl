#pragma force_active on
class muMenu {
public:
    static void startRumbleController(int, int, int);
};

extern "C" void fn_10_13C80(char* self) {
    int m = *(int*)(self + 0x1dc);
    if (m < 0) {
        return;
    }
    if (*(int*)(self + 0x1b4) != 1) {
        return;
    }
    int v = *(int*)(self + 0x1c8);
    muMenu::startRumbleController(m, 10, v);
}
