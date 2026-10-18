#pragma force_active on
struct ftPitObj {
    int dummy;
};

extern "C" {
ftPitObj* fn_112_13318(ftPitObj* self, short flag) {
    if (self != 0 && flag > 0) {
        delete self;
    }
    return self;
}
}
