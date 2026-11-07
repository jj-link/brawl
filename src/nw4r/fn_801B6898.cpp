#pragma force_active on
extern "C" {
void fn_80162B40(void*, void*, void*);
void fn_801ECD70(void*, void*, void*);
void fn_801F2284(void*, float, float, float);
void fn_801F2294(void*, float*, float*, float*);
void fn_801F22B0(void*, float, float, float);
void fn_801F22CC(void*, float*, float*, float*);
void fn_801F22F4(void*, float, float, float);
}

struct Arr {
    unsigned short n;
    char* data;
};

template <class T>
inline const T& mn(const T& a, const T& b) { return a < b ? b : a; }

extern "C" void fn_801B6898(Arr* a, void* m, unsigned int cnt) {
    unsigned int n = a->n;
    cnt = mn(cnt, n);
    char* e;
    for (unsigned int i = 0; i < cnt; i++) {
        e = a->data + i * 0x44;
        if (*(unsigned int*)e & 4) {
            float w[3];
            float v[3];
            fn_801F22CC(e + 4, &v[0], &v[1], &v[2]);
            fn_80162B40(v, m, v);
            if (*(unsigned int*)e & 8) {
                fn_801F22F4(e + 4, v[0], v[1], v[2]);
            } else {
                fn_801F2294(e + 4, &w[0], &w[1], &w[2]);
                fn_801ECD70(m, w, w);
                fn_801F2284(e + 4, w[0], w[1], w[2]);
                fn_801F22B0(e + 4, v[0], v[1], v[2]);
            }
        }
    }
}
