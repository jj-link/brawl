#pragma force_active on
struct FlagByte {
    unsigned char pad0 : 1;
    unsigned char flag : 1;
    unsigned char pad2 : 6;
};

extern "C" void fn_117_1519C(unsigned char* obj, unsigned int flag) {
    ((FlagByte*)(obj + 0xa4))->flag = flag;
}
