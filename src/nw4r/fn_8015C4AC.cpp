#include <types.h>
#pragma force_active on
struct Reader {
    u8* p;
    u8 get() const { return *p; }
    void next() { p++; }
};
extern "C" u8 fn_8015C4AC(Reader* r) {
    u8 v = r->get();
    r->next();
    return v;
}