#pragma force_active on
extern "C" void fn_802162A4(int, int);
extern "C" void fn_8021A558(int, int);

extern "C" {
void stopMotorAllForce__11gfPadSystemFv(void) {
    for (int i = 0; i < 4; i++) {
        fn_802162A4(i, 0);
    }
    for (int i = 0; i < 4; i++) {
        fn_8021A558(i, 0);
    }
}
}
