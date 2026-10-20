#pragma force_active on
typedef struct {
    int x;
    int y;
    unsigned int a : 4;
    signed int b : 4;
    unsigned int c : 24;
} NorfairWord;

extern "C" int fn_54_E490(NorfairWord* p) {
    return p->b;
}
