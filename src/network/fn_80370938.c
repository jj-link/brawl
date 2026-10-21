#pragma force_active on

typedef struct Object {
    unsigned char pad[0x444];
    void* field_444;
} Object;

#ifdef __cplusplus
extern "C" {
#endif

void fn_8035B120(void*);

void fn_80370938(Object** self) {
    fn_8035B120((*self)->field_444);
}

#ifdef __cplusplus
}
#endif
