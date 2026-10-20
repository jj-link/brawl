#pragma force_active on
class ftExtendParamAccesser {
public:
    ~ftExtendParamAccesser();
};

extern "C" {
void* __dt__21ftExtendParamAccesserFv(void*, short);

void* fn_113_C658(ftExtendParamAccesser* p, short flags) {
    if (p) {
        __dt__21ftExtendParamAccesserFv(p, 0);
        if (flags > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
