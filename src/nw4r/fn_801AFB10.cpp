#pragma force_active on

namespace {
struct HeapArg {
    unsigned char pad[0xF8];
    void* buf;
    unsigned char gap[5];
    unsigned char count;
    unsigned short elem_size;
};
}

extern "C" void* fn_801AFB10(HeapArg* p) {
    if (p->buf) {
        const unsigned stride = ((unsigned)p->elem_size * 36 + 31) & 0xFFFFFFE0u;
        return (char*)p->buf + (unsigned)p->count * stride;
    }
    return 0;
}
