namespace {
// The flag's meaning is unknown; it occupies bit 6 at offset 0xa4.
struct FlagLayout {
    unsigned char padding[0xa4];
    unsigned char : 1;
    unsigned char flag : 1;
    unsigned char : 6;
};
}

extern "C" bool fn_99_106C8(const FlagLayout* object) {
    return object->flag;
}
