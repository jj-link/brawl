// Keep the REL's four-byte-aligned article-capacity dispatch table.
#pragma section data_type ".data$pikachuB0E0" ".bss"

namespace {
struct ArticleSearchStatus {
    bool first;
    bool second;
};

// Pool capacities are fixed; kinds without a pool have no article slots.
template <unsigned Kind> inline int articleCapacity(const ArticleSearchStatus&) {
    return Kind == 0 || Kind == 3 ? 3 : Kind == 1 ? 2 : Kind == 2 ? 1 : 0;
}
}

extern "C" int fn_98_B0E0(void*, unsigned kind) {
    switch (kind) {
    case 0: { ArticleSearchStatus status = { false, false }; return articleCapacity<0>(status); }
    case 1: { ArticleSearchStatus status = { false, false }; return articleCapacity<1>(status); }
    case 2: { ArticleSearchStatus status = { false, false }; return articleCapacity<2>(status); }
    case 3: { ArticleSearchStatus status = { false, false }; return articleCapacity<3>(status); }
    case 4: { ArticleSearchStatus status = { false, false }; return articleCapacity<4>(status); }
    case 5: { ArticleSearchStatus status = { false, false }; return articleCapacity<5>(status); }
    case 6: { ArticleSearchStatus status = { false, false }; return articleCapacity<6>(status); }
    case 7: { ArticleSearchStatus status = { false, false }; return articleCapacity<7>(status); }
    case 8: { ArticleSearchStatus status = { false, false }; return articleCapacity<8>(status); }
    case 9: { ArticleSearchStatus status = { false, false }; return articleCapacity<9>(status); }
    case 10: { ArticleSearchStatus status = { false, false }; return articleCapacity<10>(status); }
    case 11: { ArticleSearchStatus status = { false, false }; return articleCapacity<11>(status); }
    case 12: { ArticleSearchStatus status = { false, false }; return articleCapacity<12>(status); }
    case 13: { ArticleSearchStatus status = { false, false }; return articleCapacity<13>(status); }
    case 14: { ArticleSearchStatus status = { false, false }; return articleCapacity<14>(status); }
    case 15: { ArticleSearchStatus status = { false, false }; return articleCapacity<15>(status); }
    case 16: { ArticleSearchStatus status = { false, false }; return articleCapacity<16>(status); }
    default: return 0;
    }
}
