#pragma force_active on
struct FtPitObj {
    int m_dummy;
};

extern "C" {
FtPitObj* fn_112_111F4(FtPitObj* self, short size) {
    if (self != 0 && size > 0) {
        delete self;
    }
    return self;
}
}
