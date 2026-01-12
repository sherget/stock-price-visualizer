#define _POSIX_C_SOURCE 200809L
#include "stock_data.h"
#include <stdio.h>

const int NUMBER_OF_ENTRIES = 20;

int main() {
    StockDataArray* data = stock_data_create(NUMBER_OF_ENTRIES);
    stock_data_generate_dummy_data(data);
    stock_data_print_entries(data);

    FILE *gnuplot_pipe = popen("gnuplot -persistent", "w");
    if (gnuplot_pipe == NULL) {
        fprintf(stderr, "Error opening gnuplot pipe\n");
        return 1;
    }

    fprintf(gnuplot_pipe, "set title 'Stockprice over Time'\n");
    fprintf(gnuplot_pipe, "set xlabel 'Datetime'\n");
    fprintf(gnuplot_pipe, "set ylabel 'Price'\n");
    fprintf(gnuplot_pipe, "plot '-' using 1:2 with lines smooth bezier\n");

    for (int i = 0; i < NUMBER_OF_ENTRIES; i++) {
        fprintf(gnuplot_pipe, "%ld %.2f\n", data->entries[i].timestamp, data->entries[i].price_in_cents / 100.0);
    }

    fprintf(gnuplot_pipe, "e\n");
    fflush(gnuplot_pipe);
    pclose(gnuplot_pipe);

    return 0;
}

