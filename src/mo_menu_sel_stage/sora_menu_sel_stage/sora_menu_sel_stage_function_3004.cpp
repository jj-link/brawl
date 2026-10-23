#pragma force_active on

extern "C" {
extern void* lbl_11_bss_8;

bool fn_11_7DA0(char*, bool, int);
void* fn_11_7DCC(char*, bool, int);
int strcmp(const char*, const char*);

struct Entry {
    unsigned char flags : 1;
    unsigned char rest : 7;
    int index;
};

int fn_11_3004(Entry* a, Entry* b) {
    bool fa = a->flags;
    bool fb = b->flags;
    int ia = a->index;
    int ib = b->index;

    if (fn_11_7DA0((char*)lbl_11_bss_8, fa, ia)) {
        return -1;
    }

    return strcmp(
        (char*)fn_11_7DCC((char*)lbl_11_bss_8, fb, ib),
        (char*)fn_11_7DCC((char*)lbl_11_bss_8, fa, ia));
}
}
