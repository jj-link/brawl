class soModuleAccesser;

namespace {
struct DededeEventMask {
    short value;
};
} // namespace

// Terminal callback of the eighth event unit: always reports false.
extern "C" bool fn_117_DF8C(void*, const DededeEventMask*, soModuleAccesser*) {
    return false;
}
