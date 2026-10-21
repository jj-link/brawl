#pragma force_active on

extern "C" int strcmp(const char*, const char*);

extern "C" void fn_800C33E0(const char** a, const char** b, const char** c)
{
    const char* av = *a;
    const char* cv = *c;
    bool ac = !((unsigned int)strcmp(cv, av) >> 31);
    const char* bv = *b;
    bool cb = !((unsigned int)strcmp(bv, cv) >> 31);

    if (ac && cb) {
        return;
    }

    if (!ac && !cb) {
        const char* t = *a;
        *a = *b;
        *b = t;
        return;
    }

    if ((unsigned int)strcmp(bv, av) >> 31) {
        const char* t = *a;
        *a = *b;
        *b = t;
    }

    if (ac) {
        const char* t = *b;
        *b = *c;
        *c = t;
    } else {
        const char* t = *a;
        *a = *c;
        *c = t;
    }
}
