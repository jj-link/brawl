// Keep the REL's four-byte-aligned parameter dispatch table.
#pragma section data_type ".data$pikachu18CA8" ".bss"

// Each parameter specialization constructs its own disabled descriptor.
// Only parameter zero exposes a four-byte value; the other slots are empty.
template <int Index> class VortexParameterDescriptor {
    bool enabled;
    bool assigned;
public:
    VortexParameterDescriptor() : enabled(false), assigned(false) {}
    ~VortexParameterDescriptor() {}
    unsigned size() const { return Index == 0 ? 4 : 0; }
};

extern "C" unsigned fn_98_18CA8(void*, unsigned index) {
    switch (index) {
    case 0: { VortexParameterDescriptor<0> descriptor; return descriptor.size(); }
    case 1: { VortexParameterDescriptor<1> descriptor; return descriptor.size(); }
    case 2: { VortexParameterDescriptor<2> descriptor; return descriptor.size(); }
    case 3: { VortexParameterDescriptor<3> descriptor; return descriptor.size(); }
    case 4: { VortexParameterDescriptor<4> descriptor; return descriptor.size(); }
    case 5: { VortexParameterDescriptor<5> descriptor; return descriptor.size(); }
    case 6: { VortexParameterDescriptor<6> descriptor; return descriptor.size(); }
    case 7: { VortexParameterDescriptor<7> descriptor; return descriptor.size(); }
    case 8: { VortexParameterDescriptor<8> descriptor; return descriptor.size(); }
    case 9: { VortexParameterDescriptor<9> descriptor; return descriptor.size(); }
    case 10: { VortexParameterDescriptor<10> descriptor; return descriptor.size(); }
    case 11: { VortexParameterDescriptor<11> descriptor; return descriptor.size(); }
    case 12: { VortexParameterDescriptor<12> descriptor; return descriptor.size(); }
    case 13: { VortexParameterDescriptor<13> descriptor; return descriptor.size(); }
    case 14: { VortexParameterDescriptor<14> descriptor; return descriptor.size(); }
    case 15: { VortexParameterDescriptor<15> descriptor; return descriptor.size(); }
    case 16: { VortexParameterDescriptor<16> descriptor; return descriptor.size(); }
    default: return 0;
    }
}
