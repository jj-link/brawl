#pragma force_active on
extern "C" {
int fn_8019238C(void**);
void fn_8018FBE0(void**);
void fn_801929CC(void**, int);
void fn_801929E4(void**, int);
void fn_801929FC(void**, int);
void fn_80192A14(void**, int);
}

#define RUN(off, call) { \
    char* base = *self; \
    int rel = *(int*)(base + off); \
    char* group = rel ? base + rel : 0; \
    unsigned int i; \
    int count; \
    count = group ? *(unsigned int*)(group + 4) : 0; \
    i = 0; \
    int pos; \
    pos = 0; \
    if (count) { \
        for (; i < (unsigned int)count; ++i, pos += 16) { \
            base = *self; \
            rel = *(int*)(base + off); \
            group = rel ? base + rel : 0; \
            int itemrel; \
            void* item = group ? ((itemrel = *(int*)(group + pos + 0x24)) ? group + itemrel : 0) : 0; \
            call; \
        } \
    } \
}

extern "C" void fn_8018F698(char** self) {
    {
        char* base = *self;
        int rel = *(int*)(base + 0x28);
        char* group = rel ? base + rel : 0;
        int pos;
        int count;
        unsigned int i;
        count = group ? *(unsigned int*)(group + 4) : 0;
        i = 0;
        pos = 0;
        if (count) {
            for (; i < (unsigned int)count; ++i, pos += 16) {
                base = *self;
                rel = *(int*)(base + 0x28);
                group = rel ? base + rel : 0;
                int itemrel;
                void* item = group ? ((itemrel = *(int*)(group + pos + 0x24)) ? group + itemrel : 0) : 0;
                fn_8019238C(&item);
            }
        }
    }
    RUN(0x30, fn_8018FBE0(&item))
    RUN(0x18, fn_801929CC(&item, 0))
    RUN(0x1c, fn_801929E4(&item, 0))
    RUN(0x20, fn_801929FC(&item, 0))
    RUN(0x24, fn_80192A14(&item, 0))
}
