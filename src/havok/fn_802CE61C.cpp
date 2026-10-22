#pragma force_active on

extern "C" {
extern char lbl_804873E8[];
}

struct Inner {
    virtual void f0(int);
    unsigned short active;
    short refs;
};

extern "C" void* fn_802CE61C(char* arg0) {
    if (arg0 != 0) {
        Inner* inner = *(Inner**)(arg0 + 0x4);
        *(char**)(arg0 + 0x0) = lbl_804873E8;
        if (inner->active != 0) {
            inner->refs = inner->refs - 1;
            if (inner->refs == 0 && inner != 0) {
                inner->f0(1);
            }
        }
    }
    return arg0;
}
