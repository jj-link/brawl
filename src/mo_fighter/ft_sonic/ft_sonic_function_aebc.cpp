#pragma force_active on
extern "C" {
unsigned int fn_123_B5C4(char*);
char* fn_123_B5D4(char*, int);
char* fn_123_B5EC(char*, int);
}

namespace {
struct FtSonicCountState {
    bool first;
    bool second;
};

template <unsigned Kind> struct FtSonicCounter {
    unsigned int (*predicate)(char*);
    unsigned int accepted;
    unsigned int rejected;

    explicit FtSonicCounter(unsigned int (*test)(char*))
        : predicate(test), accepted(0), rejected(0) {}

    inline void operator()(char* member) {
        if (predicate(member) == 1) {
            ++accepted;
        } else {
            ++rejected;
        }
    }
};

template <unsigned Kind> inline FtSonicCounter<Kind> countMembers(char* object) {
    FtSonicCounter<Kind> counter(fn_123_B5C4);
    for (int i = 0; i < 1; ++i) {
        char* member = Kind == 0 ? fn_123_B5EC(object + 0x2D48, i) : fn_123_B5D4(object + 0xC, i);
        counter(member + 0x88);
    }
    return counter;
}
}

extern "C" unsigned int fn_123_AEBC(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { FtSonicCountState state = {false, false}; return countMembers<0>(object).accepted; }
    case 1: { FtSonicCountState state = {false, false}; return countMembers<1>(object).accepted; }
    case 2: { FtSonicCountState state = {false, false}; return 0; }
    case 3: { FtSonicCountState state = {false, false}; return 0; }
    case 4: { FtSonicCountState state = {false, false}; return 0; }
    case 5: { FtSonicCountState state = {false, false}; return 0; }
    case 6: { FtSonicCountState state = {false, false}; return 0; }
    case 7: { FtSonicCountState state = {false, false}; return 0; }
    case 8: { FtSonicCountState state = {false, false}; return 0; }
    case 9: { FtSonicCountState state = {false, false}; return 0; }
    case 10: { FtSonicCountState state = {false, false}; return 0; }
    case 11: { FtSonicCountState state = {false, false}; return 0; }
    case 12: { FtSonicCountState state = {false, false}; return 0; }
    case 13: { FtSonicCountState state = {false, false}; return 0; }
    case 14: { FtSonicCountState state = {false, false}; return 0; }
    case 15: { FtSonicCountState state = {false, false}; return 0; }
    case 16: { FtSonicCountState state = {false, false}; return 0; }
    default: return 0;
    }
}
