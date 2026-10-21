#pragma force_active on

struct Visitor {
    unsigned char state;
};

struct Flags {
    unsigned char pad[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char next;
};

extern "C" void* fn_110_13980(void*, int);
extern "C" int fn_110_137D0(void*, void*, void*);
extern "C" void* fn_110_138D0(void*, int);
extern "C" void fn_110_15314(void*, void*);
extern "C" void* fn_110_13820(void*, int);

extern "C" void fn_110_1351C(void* object, void* argument) {
    Visitor visitor;
    Visitor first = visitor;
    for (int i = 0; i < 1; ++i) {
        if (!fn_110_137D0(&first, fn_110_13980((char*)object + 0x68, i), argument))
            return;
    }

    Visitor third;
    Visitor second = first;
    for (int i = 0; i < 1; ++i) {
        Flags* p = (Flags*)fn_110_138D0((char*)object + 0x48, i);
        bool flag = p->flag;
        if (flag == true && p->next == 0)
            fn_110_15314(p, argument);
    }

    third = second;
    for (int i = 0; i < 1; ++i) {
        if (!fn_110_137D0(&third, fn_110_13820((char*)object + 8, i), argument))
            return;
    }
}
