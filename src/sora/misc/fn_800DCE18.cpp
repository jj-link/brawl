#pragma force_active on
struct S {
    int pad[188];
    int val;
};

struct T {
    int pad[30];
    S* ptr;
};

extern "C" int fn_800DCE18(T* t) {
    return t->ptr->val;
}
