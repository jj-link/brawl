#pragma force_active on

struct S {
    char pad[0x54];
    unsigned char kind;
    char pad2[0x3D];
    unsigned char b;
    char pad3;
    unsigned short h;
};

extern "C" int fn_7_1414(S* s) {
    int r = 0;
    switch (s->kind) {
    case 8:
        r = s->b + 2;
        break;
    case 9:
    case 18:
        r = 7;
        break;
    case 10:
    case 16:
        r = 8;
        break;
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 17:
    default:
        if (s->h == 0x35) {
            r = 1;
        }
        break;
    }
    return r;
}
