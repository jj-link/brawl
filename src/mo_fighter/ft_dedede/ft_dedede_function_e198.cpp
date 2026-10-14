// Thunk for the second procedure of the Dedede article-mediator interface
// table (lbl_117_data_B9C, immediately before the
// "soArticleMediatorImpl<soTypeList<soInstancePoolInfo<wnDe..." type name).
//
// The interface slot receives the subobject pointer, but the primary
// implementation fn_117_BD5C expects its object pointer four bytes earlier
// (the table stores the -4 delta in the slot right before the procedure
// list). Re-derive the expected object pointer and tail-call the primary,
// forwarding the accesser and article arguments unchanged.
class soModuleAccesser;
class soArticle;

extern "C" bool fn_117_BD5C(void*, soModuleAccesser*, soArticle*);

extern "C" bool fn_117_E198(void* interface, soModuleAccesser* accesser,
                            soArticle* article) {
    return fn_117_BD5C(static_cast<unsigned char*>(interface) - 4, accesser,
                       article);
}
