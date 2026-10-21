#pragma force_active on
extern "C" {
extern int sprintf(char* buf, const char* fmt, ...);
}

struct Entry {
    int type;
    int data[4];
};

extern Entry lbl_80422F70[];
extern const char lbl_80422FE0[];

extern "C" int fn_800305FC(char* buf) {
    Entry* found = 0;
    int i = 0;
    Entry* p = lbl_80422F70;
    for (int n = 5; n > 0; n--) {
        if (p->type == 3) {
            found = &lbl_80422F70[i];
            break;
        }
        p++;
        i++;
    }
    return sprintf(buf, lbl_80422FE0, (int)found + 4);
}
