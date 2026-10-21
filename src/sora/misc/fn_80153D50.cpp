#pragma force_active on

struct Inner {
    char pad[0x1c];
    char* q;
};

extern "C" char* fn_80153D50(Inner** r3) {
    Inner* i = *r3;
    if (i == 0) {
        return 0;
    }
    return i->q + 0x20;
}
