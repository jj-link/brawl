#pragma force_active on
extern "C" {

typedef struct {
    int m_0;
    int m_4;
    int m_8;
} ftClassInfoLike;

int fn_27_FE5BC(ftClassInfoLike* self) {
    return self->m_8 >> 30;
}

}
