#pragma force_active on

struct Ent {
    int a;
    int b;
    int c;
    int d;
    int e;
};

struct G {
    char pad[0x30];
    Ent* ents;
};

extern G* g_GameGlobal;

extern "C" int fn_31_E8C() {
    int r = 0;
    Ent* p = g_GameGlobal->ents;
    int i = 0;
    do {
        if (p->a != 1 && p->b != 0) {
            switch (i) {
            case 9:
            case 11:
            case 13:
            case 15:
            case 17:
            case 18:
            case 19:
            case 20:
            case 21:
            case 25:
            case 26:
            case 27:
                if (r < 0x28)
                    r = 0x28;
                break;
            case 28:
            case 29:
            case 30:
            case 31:
            case 32:
            case 33:
                if (r < 0x50)
                    r = 0x50;
                break;
            }
        }
        i++;
        p++;
    } while (i < 0x22);
    return r;
}
