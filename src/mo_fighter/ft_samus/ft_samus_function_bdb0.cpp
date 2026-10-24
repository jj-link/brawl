#include <so/article/so_article.h>
#pragma force_active on

extern "C" {
char* fn_94_CE94(void*, int);
char* fn_94_CE5C(void*, int);
char* fn_94_CE24(void*, int);
char* fn_94_CE0C(void*, int);
char* fn_94_CDC4(void*, int);
char* fn_94_CDAC(void*, int);
char* fn_94_CD84(void*, int);
char* fn_94_CD6C(void*, int);
}

namespace {
struct State {
    bool first;
    bool second;
};

template <unsigned K>
inline bool all(char* p) {
    for (int i = 0;
         i < (K == 0 ? 4 :
              K == 1 ? 3 :
              K == 2 ? 3 :
              K == 4 ? 4 :
              K == 6 ? 2 : 1);
         ++i) {
        char* w =
            K == 0 ? fn_94_CE94(p + 0x175F0, i) :
            K == 1 ? fn_94_CE5C(p + 0x1260C, i) :
            K == 2 ? fn_94_CE24(p + 0xDA84, i) :
            K == 3 ? fn_94_CE0C(p + 0xC184, i) :
            K == 4 ? fn_94_CDC4(p + 0x6240, i) :
            K == 5 ? fn_94_CDAC(p + 0x4A00, i) :
            K == 6 ? fn_94_CD84(p + 0x17A4, i) :
                     fn_94_CD6C(p + 0xC, i);

        if (!reinterpret_cast<soArticle*>(w + 0x88)->isActiveArticle()) {
            return false;
        }
    }
    return true;
}
}

extern "C" bool fn_94_BDB0(char* p, unsigned operation, unsigned kind) {
    switch (kind) {
    case 0: { State state = {false, false}; return !all<0>(p); }
    case 1: { State state = {false, false}; return !all<1>(p); }
    case 2: { State state = {false, false}; return !all<2>(p); }
    case 3: { State state = {false, false}; return !all<3>(p); }
    case 4: { State state = {false, false}; return !all<4>(p); }
    case 5: { State state = {false, false}; return !all<5>(p); }
    case 6: { State state = {false, false}; return !all<6>(p); }
    case 7: { State state = {false, false}; return !all<7>(p); }
    case 8: { State state = {false, false}; return false; }
    case 9: { State state = {false, false}; return false; }
    case 10: { State state = {false, false}; return false; }
    case 11: { State state = {false, false}; return false; }
    case 12: { State state = {false, false}; return false; }
    case 13: { State state = {false, false}; return false; }
    case 14: { State state = {false, false}; return false; }
    case 15: { State state = {false, false}; return false; }
    case 16: { State state = {false, false}; return false; }
    default: return false;
    }
}
