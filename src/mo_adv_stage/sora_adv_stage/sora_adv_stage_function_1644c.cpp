#pragma force_active on

struct S {
    int v[10];
};

struct O {
    char pad[0xAC];
    int id;

    int getId() const {
        return id;
    }
};

extern "C" O* fn_40_15694(int, int);
extern "C" S lbl_40_data_3528;

extern "C" void fn_40_1644C(void* self, int arg1) {
    O* p = fn_40_15694((int)self, arg1);

    if (p && p->getId() == 0x2E) {
        ((unsigned char*)self)[0x1C] = 1;
        ((unsigned char*)self)[0x1D] = 1;
        return;
    }

    unsigned char flag = ((unsigned char*)self)[0x20];
    if (flag && p && p->getId() == 0x3B) {
        ((unsigned char*)self)[0x1C] = 1;
        return;
    }

    if (flag && p && p->getId() == 0x3C) {
        ((unsigned char*)self)[0x1D] = 1;
        return;
    }

    S local = lbl_40_data_3528;
    O* p2 = fn_40_15694((int)self, arg1);
    int found;
    int i;
    int* arr = (int*)&local;

    i = 0;
    while (i < 10) {
        if (p2 && *arr == p2->getId()) {
            found = 1;
            goto end;
        }
        ++arr;
        ++i;
    }

    found = 0;

end:
    if (found != 0) {
        ((unsigned char*)self)[0x1C] = 1;
    }
}
