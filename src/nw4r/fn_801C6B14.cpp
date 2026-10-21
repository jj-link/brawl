#pragma force_active on
extern "C" {
extern char lbl_80466B58[];

void fn_801C6B14(void *arg0) {
    unsigned char* p = static_cast<unsigned char*>(arg0);
    *reinterpret_cast<int*>(p + 0) = reinterpret_cast<int>(&lbl_80466B58);
    *reinterpret_cast<int*>(p + 4) = 0;
    p[8] = 0x2f;
    p[9] = 0;
}
}
