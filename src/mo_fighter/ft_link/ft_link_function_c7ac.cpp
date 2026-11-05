#include <so/article/so_article.h>
#pragma force_active on

class Class_2E08 {
public:
    virtual void fn_93_22F8();
    virtual void fn_93_1E9C();
    virtual void fn_93_B128();
    virtual void fn_93_B120();
    virtual void fn_93_B118();
    virtual void fn_93_B110();
    virtual void fn_93_B108();
};

class Class_80C0 {
public:
    virtual void fn_93_F2AC();
    virtual void fn_93_F26C();
    virtual void fn_93_F2A8();
    virtual void fn_93_F270();
    virtual void fn_93_F2A4();
    virtual void fn_93_F2A0();
    virtual void fn_93_F29C();
};

class Class_8158 {
public:
    virtual void fn_93_F424();
    virtual void fn_93_F348();
    virtual void fn_93_F2A8();
    virtual void fn_93_F420();
    virtual void fn_93_F2A4();
    virtual void fn_93_F2A0();
    virtual void fn_93_F29C();
};

class Class_81D8 {
public:
    virtual void fn_93_F6B4();
    virtual void fn_93_F4BC();
    virtual void fn_93_F630();
    virtual void fn_93_F62C();
    virtual void fn_93_F2A4();
    virtual void fn_93_F2A0();
    virtual void fn_93_F29C();
};

class Class_8384 {
public:
    virtual void fn_93_F900();
    virtual void fn_93_F74C();
    virtual void fn_93_F2A8();
    virtual void fn_93_F2EC();
    virtual void fn_93_F2A4();
    virtual void fn_93_F2A0();
    virtual void fn_93_F29C();
};

class Class_8400 {
public:
    virtual void fn_93_10DEC();
    virtual void fn_93_10630();
    virtual void fn_93_10A34();
    virtual void fn_93_F2EC();
    virtual void fn_93_F2A4();
    virtual void fn_93_F2A0();
    virtual void fn_93_F29C();
};

class Class_8478 {
public:
    virtual void fn_93_10E2C();
    virtual void fn_93_FFF8();
    virtual void fn_93_10448();
    virtual void fn_93_100A8();
    virtual void fn_93_F2A4();
    virtual void fn_93_F2A0();
    virtual void fn_93_F29C();
};

class Class_84F0 {
public:
    virtual void fn_93_10E6C();
    virtual void fn_93_F998();
    virtual void fn_93_FC4C();
    virtual void fn_93_F2EC();
    virtual void fn_93_F2A4();
    virtual void fn_93_F2A0();
    virtual void fn_93_F29C();
};

class Class_8568 {
public:
    virtual void fn_93_10FEC();
    virtual void fn_93_10F5C();
    virtual void fn_93_F2A8();
    virtual void fn_93_10F60();
    virtual void fn_93_10FE8();
    virtual void fn_93_F2A0();
    virtual void fn_93_F29C();
};

class Class_8B7C {
public:
    virtual void fn_93_22F8();
    virtual void fn_93_12AB4();
    virtual void fn_93_14638();
    virtual void fn_93_14634();
    virtual void fn_93_14630();
    virtual void fn_93_1462C();
    virtual void fn_93_14624();
};

class Class_8D00 {
public:
    virtual void fn_93_22F8();
    virtual void fn_93_12B10();
    virtual void fn_93_147F4();
    virtual void fn_93_147EC();
    virtual void fn_93_147E4();
    virtual void fn_93_147DC();
    virtual void fn_93_147D4();
};

class Class_8E7C {
public:
    virtual void fn_93_22F8();
    virtual void fn_93_12CB0();
    virtual void fn_93_148B8();
    virtual void fn_93_148B0();
    virtual void fn_93_148A8();
    virtual void fn_93_148A4();
    virtual void fn_93_1489C();
};

class Class_8EF0 {
public:
    virtual void fn_93_14B84();
    virtual void fn_93_14B34();
    virtual void fn_93_F2A8();
    virtual void fn_93_F2EC();
    virtual void fn_93_F2A4();
    virtual void fn_93_F2A0();
    virtual void fn_93_F29C();
};

class Class_8F70 {
public:
    virtual void fn_93_152BC();
    virtual void fn_93_14C1C();
    virtual void fn_93_F2A8();
    virtual void fn_93_14D9C();
    virtual void fn_93_F2A4();
    virtual void fn_93_F2A0();
    virtual void fn_93_F29C();
};

extern "C" {
extern const char lbl_93_data_7DFC[], lbl_93_data_7C94[], lbl_93_data_7B28[];
extern const char lbl_93_data_785C[], lbl_93_data_79C4[], lbl_93_data_34EC[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_93_A740();
int fn_27_2DEB94(void*, void*, int);
int fn_93_A548(void*, int);
}

extern "C" int fn_93_C7AC(void*, int operation, soArticle* article)
{
    short one = 1;
    switch (article->getArticleId()) {
    case 0: {
        bool flags[2] = {false, false};
        __dynamic_cast(article, 0, lbl_93_data_7DFC, lbl_93_data_34EC, one);
        return 1;
    }
    case 1: {
        bool flags[2] = {false, false};
        void* weapon = __dynamic_cast(article, 0, lbl_93_data_7C94, lbl_93_data_34EC, one);
        return fn_27_2DEB94(fn_93_A740(), weapon, operation);
    }
    case 2: {
        bool flags[2] = {false, false};
        void* weapon = __dynamic_cast(article, 0, lbl_93_data_7B28, lbl_93_data_34EC, one);
        return fn_93_A548(weapon, operation);
    }
    case 3: {
        bool flags[2] = {false, false};
        __dynamic_cast(article, 0, lbl_93_data_785C, lbl_93_data_34EC, one);
        return 1;
    }
    case 4: {
        bool flags[2] = {false, false};
        __dynamic_cast(article, 0, lbl_93_data_79C4, lbl_93_data_34EC, one);
        return 1;
    }
    case 5: {
        bool flags[2] = {false, false};
        __dynamic_cast(article, 0, lbl_93_data_79C4, lbl_93_data_34EC, one);
        return 1;
    }
    case 6: { bool flags[2] = {false, false}; return 1; }
    case 7: { bool flags[2] = {false, false}; return 1; }
    case 8: { bool flags[2] = {false, false}; return 1; }
    case 9: { bool flags[2] = {false, false}; return 1; }
    case 10: { bool flags[2] = {false, false}; return 1; }
    case 11: { bool flags[2] = {false, false}; return 1; }
    case 12: { bool flags[2] = {false, false}; return 1; }
    case 13: { bool flags[2] = {false, false}; return 1; }
    case 14: { bool flags[2] = {false, false}; return 1; }
    case 15: { bool flags[2] = {false, false}; return 1; }
    case 16: { bool flags[2] = {false, false}; return 1; }
    default: return 0;
    }
}
