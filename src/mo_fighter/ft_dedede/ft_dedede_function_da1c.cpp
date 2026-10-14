class soModuleAccesser;

namespace {
struct DededeEventMask {
    short value;
};
} // namespace

// Terminal callback of the second event unit: always reports false.
extern "C" bool fn_117_DA1C(void*, const DededeEventMask*, soModuleAccesser*) {
    return false;
}
