#pragma force_active on
extern "C" void* fn_105_1C398(void* object, int index);
extern "C" void fn_105_1C360(void* object, void* arg);

struct Flags {
    unsigned char hi : 1;
    unsigned char rest : 7;
};

extern "C" void fn_105_1C16C(void* object, void* arg) {
    for (int i = 0; i < 1; i++) {
        unsigned char* p = (unsigned char*)fn_105_1C398((char*)object + 8, i);
        Flags* f = (Flags*)(p + 5);
        bool flag = f->hi;
        if (flag == true && p[6] == 0) {
            fn_105_1C360(p, arg);
        }
    }
}
