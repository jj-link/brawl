#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Outer {
    u8 pad[0x458];
    u16 f458;
    u16 f45a;
};

struct Arg {
    void* unk0;
    u8 pad[4];
    void* unk8;

    void* getFirst() const { return unk0; }
};

struct Rec {
    void* a;
    void* b;
    void* c;
    u8 d;
    u8 flag : 1;

    void clear() {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        flag = 0;
    }
};

extern "C" void fn_80111968(void*, void*, void*, int);
extern "C" void fn_80113DF8(void*, void**);
extern "C" void fn_80113EC0(void*, void**);
extern "C" void fn_8012FABC(void*, void*, u32);
extern "C" void fn_8012FE3C(void*, void*, u32);

struct Output {
    u8 data[24];

    Output(void* const& second, void* first) {
        fn_80111968(second, this, first, 0);
    }
};

extern "C" int fn_8012F6AC(Outer& arg0, const Arg& arg1, int arg2) {
    Output out(arg1.unk8, arg1.getFirst());
    Rec rec1;
    Rec rec0;

    u8 found = false;
    bool ok;

    rec1.clear();
    rec0.clear();

    if ((arg0.f458 & 0xA) == 0) {
        fn_80113DF8((void*)&arg1, &rec0.a);
        Rec& r0 = rec0;
        if (r0.a != 0) {
            if (r0.b != 0 && r0.c != 0)
                found = true;
        }
        if (found && ((((u8*)r0.b)[0x54] >> 4) & 1) &&
            ((((u8*)r0.c)[0x2C] >> 7) & 1))
            ok = true;
        else
            ok = false;
        if (ok && ((((u8*)r0.a)[0xF]) & 1)) {
            int m = arg0.f45a & 6;
            if (m != 6 && m == 0)
                fn_8012FABC(&arg0, (void*)&arg1, arg2);
        }
    }

    if ((arg0.f458 & 6) == 0) {
        fn_80113EC0((void*)&arg1, &rec1.a);
        bool found2 = false;
        if (rec1.a != 0 && rec1.b != 0 && rec1.c != 0)
            found2 = true;
        if (found2 && ((((u8*)rec1.b)[0x54] >> 4) & 1) &&
            ((((u8*)rec1.c)[0x2C] >> 7) & 1))
            ok = true;
        else
            ok = false;
        Rec& r1 = rec1;
        if (ok && ((((u8*)r1.a)[0xF] >> 1) & 1)) {
            int m = arg0.f45a & 5;
            if (m != 5 && m == 0)
                fn_8012FE3C(&arg0, (void*)&arg1, arg2);
        }
    }

    return 1;
}
