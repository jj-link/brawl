#pragma force_active on
extern const float lbl_805A2BA8;
struct Entry { int id; int unused; float x; float y; };
struct Object { int count; Entry e[35][40]; };
extern "C" Object* fn_8015B0E0(Object* self) {
    unsigned int i;
    int j;
    Object* row = self;
    self->count = 0;
    for (i = 0; i < 35; ++i, row = (Object*)((char*)row + 640)) {
        Object* p = row;
        for (j = 0; j < 5; ++j, p = (Object*)((char*)p + 128)) {
            p->e[0][0].id = -1;
            p->e[0][0].x = lbl_805A2BA8;
            p->e[0][0].y = lbl_805A2BA8;
            p->e[0][1].id = -1;
            p->e[0][1].x = lbl_805A2BA8;
            p->e[0][1].y = lbl_805A2BA8;
            p->e[0][2].id = -1;
            p->e[0][2].x = lbl_805A2BA8;
            p->e[0][2].y = lbl_805A2BA8;
            p->e[0][3].id = -1;
            p->e[0][3].x = lbl_805A2BA8;
            p->e[0][3].y = lbl_805A2BA8;
            p->e[0][4].id = -1;
            p->e[0][4].x = lbl_805A2BA8;
            p->e[0][4].y = lbl_805A2BA8;
            p->e[0][5].id = -1;
            p->e[0][5].x = lbl_805A2BA8;
            p->e[0][5].y = lbl_805A2BA8;
            p->e[0][6].id = -1;
            p->e[0][6].x = lbl_805A2BA8;
            p->e[0][6].y = lbl_805A2BA8;
            p->e[0][7].id = -1;
            p->e[0][7].x = lbl_805A2BA8;
            p->e[0][7].y = lbl_805A2BA8;
        }
    }
    return self;
}