#pragma force_active on

struct Holder {
    char pad[0x24];
    unsigned int flags;
};

struct Arg0 {
    char pad[4];
    Holder* holder;
};

extern "C" void fn_8015A138(Arg0* arg0, int arg1, int arg2) {
    if (arg1) {
        arg0->holder->flags &= 0xFFFFEFFF;
        arg0->holder->flags &= 0xFFFFDFFF;
        arg0->holder->flags |= 0x4000;
        arg0->holder->flags |= 0x8000;
    } else {
        arg0->holder->flags |= 0x1000;
        arg0->holder->flags |= 0x2000;
        arg0->holder->flags &= 0xFFFFBFFF;
        arg0->holder->flags &= 0xFFFF7FFF;
    }
    arg0->holder->flags &= 0xFFFEFFFF;
    arg0->holder->flags &= 0xFFFDFFFF;
    arg0->holder->flags &= 0xFFFBFFFF;
    arg0->holder->flags &= 0xFFF7FFFF;
    arg0->holder->flags &= 0xFFEFFFFF;
    arg0->holder->flags &= 0xFFDFFFFF;
    arg0->holder->flags &= 0xFFBFFFFF;
    arg0->holder->flags &= 0xFF7FFFFF;
    switch (arg2) {
    case 0:
        arg0->holder->flags |= 0x10000;
        return;
    case 1:
        arg0->holder->flags |= 0x20000;
        return;
    case 2:
        if (arg1) {
            arg0->holder->flags |= 0x80000;
            return;
        }
        arg0->holder->flags |= 0x40000;
        return;
    case 3:
        if (arg1) {
            arg0->holder->flags |= 0x200000;
            return;
        }
        arg0->holder->flags |= 0x100000;
        return;
    case 4:
        if (arg1) {
            arg0->holder->flags |= 0x800000;
            return;
        }
        arg0->holder->flags |= 0x400000;
        return;
    default:
        arg0->holder->flags |= 0x20000;
        return;
    }
}
