// Keep the generated jump table four-byte aligned at its original REL address.
#pragma section data_type ".data$ness19b8c" ".bss"

// A typed bank query copies its selection state into the capacity operation.
template <unsigned Kind> struct NessArticleBankSelection {
    bool selected;
    NessArticleBankSelection() : selected(false) {}
};

template <unsigned Kind>
inline unsigned bankCapacity(NessArticleBankSelection<Kind>) {
    return Kind == 0 ? 6 : 0;
}

extern "C" unsigned fn_101_19B8C(void*, unsigned kind) {
    switch (kind) {
    case 0: return bankCapacity(NessArticleBankSelection<0>());
    case 1: return bankCapacity(NessArticleBankSelection<1>());
    case 2: return bankCapacity(NessArticleBankSelection<2>());
    case 3: return bankCapacity(NessArticleBankSelection<3>());
    case 4: return bankCapacity(NessArticleBankSelection<4>());
    case 5: return bankCapacity(NessArticleBankSelection<5>());
    case 6: return bankCapacity(NessArticleBankSelection<6>());
    case 7: return bankCapacity(NessArticleBankSelection<7>());
    case 8: return bankCapacity(NessArticleBankSelection<8>());
    case 9: return bankCapacity(NessArticleBankSelection<9>());
    case 10: return bankCapacity(NessArticleBankSelection<10>());
    case 11: return bankCapacity(NessArticleBankSelection<11>());
    case 12: return bankCapacity(NessArticleBankSelection<12>());
    case 13: return bankCapacity(NessArticleBankSelection<13>());
    case 14: return bankCapacity(NessArticleBankSelection<14>());
    case 15: return bankCapacity(NessArticleBankSelection<15>());
    case 16: return bankCapacity(NessArticleBankSelection<16>());
    default: return 0;
    }
}
