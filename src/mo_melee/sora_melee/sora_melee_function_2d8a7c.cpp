#pragma force_active on
class ftManager {
public:
    int getPlayerNo(int);
};

extern ftManager* g_ftManager;

extern "C" void fn_27_2D8A7C(int a, int b, int c) {
    g_ftManager->getPlayerNo(b);
    g_ftManager->getPlayerNo(c);
}
