#pragma force_active on
typedef unsigned char u8;

struct Flags {
    u8 pad[5];
    u8 flag : 1;
    u8 rest : 7;
    u8 next;
};

extern "C" void* fn_123_17A3C(void* object, int index);
extern "C" void* fn_123_1798C(void* object, int index);
extern "C" void fn_123_18484(void* energy, void* accesser);
extern "C" void fn_123_17ED8(void* energy, void* accesser);

extern "C" void fn_123_17730(void* object, void* arg) {
    for (int i = 0; i < 1; i++) {
        Flags* p = (Flags*)fn_123_17A3C((char*)object + 0x48, i);
        bool f = p->flag;
        if (f == true && p->next == 0) {
            fn_123_18484(p, arg);
        }
    }
    for (int i = 0; i < 1; i++) {
        Flags* p = (Flags*)fn_123_1798C((char*)object + 8, i);
        bool f = p->flag;
        if (f == true && p->next == 0) {
            fn_123_17ED8(p, arg);
        }
    }
}
