// Keep the generated jump table four-byte aligned at its original REL address.
#pragma section data_type ".data$luigi97e0" ".bss"

// The bank-capacity operation receives a copy of its typed selection state.
template <unsigned Kind> struct LuigiArticleBankSelection {
    bool selected;
    LuigiArticleBankSelection() : selected(false) {}
};

template <unsigned Kind>
inline unsigned bankCapacity(LuigiArticleBankSelection<Kind>) {
    return Kind == 0 ? 2 : Kind == 1 ? 1 : 0;
}

extern "C" unsigned fn_99_97E0(void*, unsigned kind) {
    switch (kind) {
    case 0: return bankCapacity(LuigiArticleBankSelection<0>());
    case 1: return bankCapacity(LuigiArticleBankSelection<1>());
    case 2: return bankCapacity(LuigiArticleBankSelection<2>());
    case 3: return bankCapacity(LuigiArticleBankSelection<3>());
    case 4: return bankCapacity(LuigiArticleBankSelection<4>());
    case 5: return bankCapacity(LuigiArticleBankSelection<5>());
    case 6: return bankCapacity(LuigiArticleBankSelection<6>());
    case 7: return bankCapacity(LuigiArticleBankSelection<7>());
    case 8: return bankCapacity(LuigiArticleBankSelection<8>());
    case 9: return bankCapacity(LuigiArticleBankSelection<9>());
    case 10: return bankCapacity(LuigiArticleBankSelection<10>());
    case 11: return bankCapacity(LuigiArticleBankSelection<11>());
    case 12: return bankCapacity(LuigiArticleBankSelection<12>());
    case 13: return bankCapacity(LuigiArticleBankSelection<13>());
    case 14: return bankCapacity(LuigiArticleBankSelection<14>());
    case 15: return bankCapacity(LuigiArticleBankSelection<15>());
    case 16: return bankCapacity(LuigiArticleBankSelection<16>());
    default: return 0;
    }
}
