#include <sr/sr_common.h>
#pragma force_active on

struct BuildData {
    char pad0[4];
    int f4;
    char pad8[0x28];
    int f30;
    char pad34[0x24];
    int f58;
    int f5c;
    char pad60[4];
    int f64;
    int f68;
    char pad6c[4];
    int f70;
};

struct State {
    unsigned char flags : 1;
    unsigned char remaining : 7;
    BuildData* data;
    unsigned char enabled;
    void* first;
    void* second;
};

extern "C" {
extern void* g_aiMgr;
void* fn_27_1F329C(void*, int, int, int, int, int, void*, Heaps::HeapType);
void fn_27_1F1AD4(void*, int, int);
void fn_27_1F13E4(int, int, int);
}

inline void* create(int a, int b, int c, int d, int mode,
                    void* parent, Heaps::HeapType heap) {
    void* p = operator new(0x11c, heap);
    if (p)
        p = fn_27_1F329C(p, d, c, b, a, mode, parent, heap);
    return p;
}

inline void* createOrdered(BuildData* data, Heaps::HeapType heap) {
    int d, c, b, a;
    a = data->f30;
    b = data->f58;
    c = data->f4;
    d = data->f70;
    return create(a, b, c, d, 0, 0, heap);
}

inline void* createSecondary(BuildData* data, void* parent,
                             Heaps::HeapType heap) {
    int d, c, b;
    b = data->f58;
    c = data->f4;
    d = data->f70;
    return create(0x10, b, c, d, 1, parent, heap);
}

inline void* createPrimary(BuildData* data, int mode, Heaps::HeapType heap) {
    int d, c, b, a;
    a = data->f30;
    b = data->f58;
    c = data->f4;
    d = data->f70;
    return create(a, b, c, d, mode, 0, heap);
}

extern "C" State* fn_27_123D78(State* self, BuildData* data,
                              Heaps::HeapType heap) {
    self->data = data;
    self->flags = 0;
    self->enabled = 1;
    self->first = 0;
    self->second = 0;

    void* first = 0;
    void* second = 0;

    switch (data->f64) {
    case 2:
    default:
        break;
    case 0:
        switch (data->f5c) {
        case 0x10:
            first = createOrdered(data, heap);
            second = createSecondary(data, first, heap);
            break;
        default:
            first = createPrimary(data, 0, heap);
            break;
        }
        break;
    case 1:
        switch (data->f5c) {
        case 0x10:
            first = createPrimary(data, 1, heap);
            second = createSecondary(data, first, heap);
            break;
        default:
            first = createPrimary(data, 1, heap);
            break;
        }
        break;
    }

    self->first = first;
    self->second = second;
    fn_27_1F1AD4(g_aiMgr, self->data->f58, self->data->f68);
    fn_27_1F13E4(self->data->f58, 0, 1);
    return self;
}
