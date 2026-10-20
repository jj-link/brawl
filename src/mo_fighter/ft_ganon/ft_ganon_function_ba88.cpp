#pragma force_active on
extern "C" void fn_109_E470(void* obj, void* arg);
extern "C" void fn_109_BFA8(short* destination, const short* source);
extern "C" void fn_109_BB18(void* obj, short* local, void* arg);

struct FlagByte {
    unsigned char hi : 1;
    unsigned char rest : 7;
};

extern "C" void fn_109_BA88(unsigned char* obj, const short* source, void* arg) {
    unsigned char* sub = obj + 0xC;
    if ((source[0] & 1) != 0) {
        FlagByte* flags = reinterpret_cast<FlagByte*>(sub + 5);
        bool hiSet = flags->hi;
        if (hiSet == true && sub[6] == 0) {
            fn_109_E470(sub, arg);
        }
    }
    short local[4];
    fn_109_BFA8(local, source);
    fn_109_BB18(obj + 4, local, arg);
}
