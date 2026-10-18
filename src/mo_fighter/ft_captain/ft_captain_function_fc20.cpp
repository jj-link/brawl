#include <so/so_module_accesser.h>
#pragma force_active on

namespace {
struct CaptainArticleLink {
    unsigned int taskId;
    int linkNo;
    char reserved[0x1c];
    unsigned char active : 1;
    unsigned char flags : 7;
    char padding[3];
};
}

extern "C" {
extern CaptainArticleLink* lbl_100_bss_268;
}

extern "C" void fn_100_FC20(soModuleAccesser* accesser) {
    soWorkManageModule* work = &accesser->getWorkManageModule();
    soLinkModule* link = &accesser->getLinkModule();
    int count = work->getInt(0x20000000);
    int i;
    CaptainArticleLink* article;
    article = lbl_100_bss_268;
    i = 0;
    while (i < count) {
        if (article->taskId != 0xffffffff && link->isLink(article->linkNo)) {
            link->unlink(article->linkNo);
            article->linkNo = -1;
        }
        ++i;
        ++article;
    }
}
