#pragma force_active on
typedef unsigned char u8;

struct Flags {
    u8 pad[5];
    u8 flag : 1;
    u8 rest : 7;
    u8 next;
};

extern "C" void* fn_113_1CFE4(void*, int);
extern "C" void fn_113_2A388(void*, int);

extern "C" void fn_113_2A194(void* obj, int arg) {
    for (int i = 0; i < 1; i++) {
        Flags* p = (Flags*)fn_113_1CFE4((char*)obj + 8, i);
        bool f = p->flag;
        if (f == true && p->next == 0) {
            fn_113_2A388(p, arg);
        }
    }
}
