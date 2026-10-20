#pragma force_active on
struct Flags50 {
    unsigned char a : 3;
    unsigned char b : 1;
    unsigned char c : 4;
};

extern "C" void fn_41_2B884(unsigned char* obj, int flag) {
    Flags50* f = (Flags50*)(obj + 0x50);
    f->b = flag;
}
