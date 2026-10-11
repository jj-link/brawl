struct MarioDefaultRecord {
    unsigned char prefix[8];
    int field08;
    int field0C;
    int field10;
};
struct MarioDefaultIntegerPair { int first; int second; };
struct MarioDefaultFloatPair { float first; float second; };
extern "C" {
extern const float lbl_91_rodata_34;
void fn_91_10338(MarioDefaultRecord* record, int value) {
    record->field08 = record->field0C = record->field10 = value;
}
int fn_91_10348(void*) { return -1; }
// Empty interface hooks reproduce the original callbacks.
void fn_91_10350(void*) {}
void fn_91_10354(void*) {}
void fn_91_10358(void*) {}
void fn_91_1035C(void*) {}
void fn_91_10360(void*) {}
MarioDefaultIntegerPair fn_91_10364(void*) {
    MarioDefaultIntegerPair pair = { 0, 0 };
    return pair;
}
bool fn_91_10380(void*) { return false; }
MarioDefaultFloatPair fn_91_10388(void*) {
    MarioDefaultFloatPair pair = { lbl_91_rodata_34, lbl_91_rodata_34 };
    return pair;
}
MarioDefaultFloatPair fn_91_103AC(void*) {
    MarioDefaultFloatPair pair = { lbl_91_rodata_34, lbl_91_rodata_34 };
    return pair;
}
void fn_91_103D0(void*) {}
}
