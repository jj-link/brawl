#pragma force_active on
extern "C" char* fn_8029F098(char* s, char c) {
    while (*s != c) {
        if (*s == 0)
            return 0;
        s++;
    }
    return s;
}
