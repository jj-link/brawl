#include <types.h>
#pragma force_active on

struct Reader {
    u16* p;
    u16 get() const { return *p; }
    void next() { p++; }
};

extern "C" u16 fn_8015C490(Reader* r) {
    u16 v = r->get();
    r->next();
    return v;
}
