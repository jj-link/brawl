#pragma force_active on
struct Obj {
    char pad[0x64];
    int val;
};

struct Wrapper {
    struct Obj *obj;
    char pad[6];
    unsigned char flag;
};

extern "C" void fn_27_112C7C(struct Wrapper *w, int n)
{
    if (w->flag != 1) {
        return;
    }
    struct Obj *o = w->obj;
    int room = 0x7FFFFFFF - o->val;
    if (room < n) {
        n = room;
    }
    o->val += n;
}
