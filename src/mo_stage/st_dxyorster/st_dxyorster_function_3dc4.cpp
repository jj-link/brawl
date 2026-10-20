#pragma force_active on
struct S {
    char pad[8];
    int a : 5;
    int b : 5;
};

extern "C" int fn_76_3DC4(S* s) {
    return s->b;
}
