#pragma force_active on
typedef unsigned int (*ToonLinkCallback)(unsigned int);

struct ToonLinkObject {
    ToonLinkCallback callback;
    int success;
    int failure;
};

extern "C" int fn_121_CC3C(ToonLinkObject* self, void* object) {
    if (self->callback((unsigned int)object + 0x88) == 1) {
        self->success += 1;
    } else {
        self->failure += 1;
    }
    return 1;
}
