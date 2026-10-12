// The article bank query owns a four-byte-aligned dispatch table.
#pragma section data_type ".data$luigi9568" ".bss"

extern "C" {
unsigned int fn_99_9CA4(void*);
unsigned char* fn_99_9CB4(void*, int);
unsigned char* fn_99_9CCC(void*, int);
}

namespace {
template<unsigned Kind> struct ArticleBankSelection {
    bool selected;
    ArticleBankSelection() : selected(false) {}
};
template<unsigned Kind> struct PredicateCount {
    unsigned int (*predicate)(void*);
    unsigned int matched;
    unsigned int rejected;
    PredicateCount() : predicate(fn_99_9CA4), matched(0), rejected(0) {}
    void operator()(unsigned char* element) {
        if (predicate(element + 0x88) == 1)
            ++matched;
        else
            ++rejected;
    }
};
template<unsigned Kind> PredicateCount<Kind> count(unsigned char* object, ArticleBankSelection<Kind>) {
    PredicateCount<Kind> result;
    for (int i = 0; i < (Kind == 0 ? 2 : 1); ++i)
        result(Kind == 0 ? fn_99_9CCC(object + 0x20A8, i) : fn_99_9CB4(object + 0xC, i));
    return result;
}
template<unsigned Kind> unsigned int countEmpty(ArticleBankSelection<Kind>) {
    return 0;
}
}

extern "C" unsigned int fn_99_9568(unsigned char* object, unsigned int, unsigned int kind) {
    switch (kind) {
    case 0: return count(object, ArticleBankSelection<0>()).matched;
    case 1: return count(object, ArticleBankSelection<1>()).matched;
    case 2: return countEmpty(ArticleBankSelection<2>());
    case 3: return countEmpty(ArticleBankSelection<3>());
    case 4: return countEmpty(ArticleBankSelection<4>());
    case 5: return countEmpty(ArticleBankSelection<5>());
    case 6: return countEmpty(ArticleBankSelection<6>());
    case 7: return countEmpty(ArticleBankSelection<7>());
    case 8: return countEmpty(ArticleBankSelection<8>());
    case 9: return countEmpty(ArticleBankSelection<9>());
    case 10: return countEmpty(ArticleBankSelection<10>());
    case 11: return countEmpty(ArticleBankSelection<11>());
    case 12: return countEmpty(ArticleBankSelection<12>());
    case 13: return countEmpty(ArticleBankSelection<13>());
    case 14: return countEmpty(ArticleBankSelection<14>());
    case 15: return countEmpty(ArticleBankSelection<15>());
    case 16: return countEmpty(ArticleBankSelection<16>());
    default: return 0;
    }
}
