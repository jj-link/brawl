#pragma force_active on
struct ThreeWords {
    unsigned int x;
    unsigned int y;
    unsigned int z;
};

struct Source {
    unsigned int padding[2];
    ThreeWords value;
};

extern "C" void fn_27_8A9F8(ThreeWords* destination, const Source* source) {
    *destination = source->value;
}
