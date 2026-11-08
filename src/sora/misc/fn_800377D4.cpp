#pragma force_active on
struct Flags {
    unsigned int type : 4;
    unsigned int reserved : 9;
    unsigned int status : 7;
    unsigned int rest : 12;
};
extern "C" void fn_80037800(void*, unsigned int);
extern "C" void fn_800377D4(void* self) {
    unsigned int status;
    int value;
    status = (*(const unsigned int*)((const char*)self + 0xB0) >> 12) & 0x7F;
    if (status != 0) {
    } else {
        value = *(int*)((char*)self + 0xB0);
        if ((value >> 28) == 0) {
            ((Flags*)((char*)self + 0xB0))->type = 1;
            fn_80037800(self, *(unsigned int*)((char*)self + 0xB0));
        }
    }
}
