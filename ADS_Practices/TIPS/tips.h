#ifndef TIPS_H
#define TIPS_H



void TIPS_add_receipt(
    const char *waitress,
    double check,
    double tip
);

void TIPS_init(
    void
);

void TIPS_close(
    void
); 

void TIPS_print_receipts(
    void
);


#endif  /* #ifndef TIPS_H */