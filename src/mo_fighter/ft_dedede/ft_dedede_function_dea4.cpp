class soModuleAccesser;

namespace {
struct DededeEventMask {
    short value;
};
} // namespace

// Terminal callback of the seventh event unit: always reports false.
extern "C" bool fn_117_DEA4(void*, const DededeEventMask*, soModuleAccesser*) {
    return false;
}
