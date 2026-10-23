#pragma force_active on
struct S {
    char* buf;
    int unk4;
    int count;
};

void fn_803737E8(struct S* s, char c) {
    s->buf[s->count++] = c;
}
