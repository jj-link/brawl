#pragma force_active on
extern "C" int sprintf(char*, const char*, ...);

struct Entry {
    int unk0;
    const char* str;
};

extern const Entry lbl_804069A0[];
extern char lbl_8059CE38[3];

extern "C" {
void fn_8004F300(char* buf, int idx) {
    sprintf(buf, lbl_8059CE38, lbl_804069A0[idx].str);
}
}
