#pragma force_active on

extern "C" {
void fn_91_D548(void*, void*);
void fn_91_DAB8(short*, const short*);
void fn_91_D628(void*, short*, void*);
}

struct FlagByte {
    unsigned char hi : 1;
    unsigned char rest : 7;
};

extern "C" void fn_91_D598(void* object, const short* source, void* param) {
    short buf[4];
    unsigned char* sub = static_cast<unsigned char*>(object) + 0xc;
    if (source[0] & 1) {
        bool flag = reinterpret_cast<FlagByte*>(sub + 5)->hi;
        if (flag == true) {
            if (sub[6] == 0) {
                fn_91_D548(sub, param);
            }
        }
    }
    fn_91_DAB8(buf, source);
    fn_91_D628(static_cast<unsigned char*>(object) + 4, buf, param);
}
