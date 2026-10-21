#pragma force_active on
class NtReport {
public:
    void report(const char*, ...);
};

extern char lbl_8045F4A8[];

extern "C" int fn_80146F34(unsigned char* p) {
    unsigned char a = p[0];
    int r = (unsigned char)(a + p[1]) == 0;
    if (!r) {
        ((NtReport*)lbl_8045F4A8)->report((const char*)a);
    }
    return r;
}
