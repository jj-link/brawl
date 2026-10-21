#pragma force_active on
extern "C" void fn_802A4C7C(int, int, int, unsigned char*);

extern "C" void fn_802A4C40(int self, int arg1, unsigned char* arg2) {
    unsigned char sp8;

    if (arg1 > 1) {
        sp8 = *arg2;
        fn_802A4C7C(self, 0, arg1 - 1, &sp8);
    }
}
