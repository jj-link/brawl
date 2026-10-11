struct MarioAdapterState {
    unsigned char prefix[12];
    int value;
};
extern "C" {
void* fn_91_5CC4(void*, short);
extern unsigned char lbl_27_bss_1CC[];
void* fn_91_101B8(void* object, short deleting) {
    if (object != 0) {
        fn_91_5CC4(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
bool fn_91_10214(void*) { return true; }
// The original interface does no work in these hooks.
void fn_91_1021C(void*) {}
bool fn_91_10220(void*) { return false; }
bool fn_91_10228(void*) { return false; }
bool fn_91_10230(void*) { return false; }
bool fn_91_10238(void*) { return false; }
void fn_91_10240(void*) {}
void* fn_91_10244(void*) { return lbl_27_bss_1CC; }
void fn_91_10250(void*) {}
void fn_91_10254(MarioAdapterState* state, int value) { state->value = value; }
int fn_91_1025C(MarioAdapterState* state) { return state->value; }
void fn_91_10264(void*) {}
}
