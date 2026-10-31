#pragma force_active on

extern "C" void fn_80227728(int, void*, int);
extern "C" void fn_80037800(void*, unsigned int);
extern "C" unsigned int OSGetTick();

struct Fn8003718CFlagBits {
    unsigned int type : 4;
    unsigned int reserved : 9;
    unsigned int status : 7;
    unsigned int rest : 12;
};

union Fn8003718CFlags {
    unsigned int word;
    Fn8003718CFlagBits bits;
};

extern "C" void fn_8003718C(void* self) {
    char buffer[0x840];
    unsigned int status;
    int value;

    if (((*(unsigned int*)((char*)self + 0xB0) >> 12) & 0x7F) == 0) {
        for (int i = 0; i < 4; i++) {
            fn_80227728(i, buffer, 0x10);
        }

        status = (*(const unsigned int*)((const char*)self + 0xB0) >> 12) & 0x7F;
        if (status != 0) {
        } else {
            value = ((Fn8003718CFlags*)((char*)self + 0xB0))->word;
            if ((value >> 28) == 0) {
                ((Fn8003718CFlags*)((char*)self + 0xB0))->bits.type = 1;
                fn_80037800(self, ((Fn8003718CFlags*)((char*)self + 0xB0))->word);
            }
        }

        *(unsigned char*)((char*)self + 0xB1) |= 0x10;
    } else {
        *(unsigned char*)((char*)self + 0xB1) |= 8;
        *(unsigned char*)((char*)self + 0xB8) = 0;
        *(unsigned int*)((char*)self + 0xBC) = OSGetTick();
        *(unsigned char*)((char*)self + 0xC0) = 0;
    }
}
