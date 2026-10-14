class soModuleAccesser;

namespace {
struct DededeEventMask {
    short value;
};
} // namespace

// Terminal callback of the fifth event unit: always reports false.
extern "C" bool fn_117_DCD4(void*, const DededeEventMask*, soModuleAccesser*) {
    return false;
}
