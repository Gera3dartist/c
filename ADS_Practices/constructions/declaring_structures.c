#include <stdio.h>

typedef struct address_s
{
    char *street;
    char *city;
} ADDRESS_t, *ADDRESS_p_t;

static void print_address(
    ADDRESS_p_t address_info
);

static void print_an_address( void ) {
    ADDRESS_t address;
    address.city = "Kyiv";
    address.street = "Shukhevycha";
    print_address(&address);
}

int main(void) {
    print_an_address();
    return 0;
}