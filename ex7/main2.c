#include <stdio.h>
#include <string.h>

typedef struct Books {
    int id;
    int price;
    char title[100];
} book_t;

void total_price(book_t books[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += books[i].price;
    }
    printf("Total Price: %d\n", total);
}

void list_books(book_t books[], int n) {
    printf("+----------+--------------+--------------------------------------------------+\n");
    printf("| %-8s | %-12s | %-48s |\n", "Id (int)", "Price (int)", "Title (string)");
    printf("+----------+--------------+--------------------------------------------------+\n");
    for (int i = 0; i < n; i++) {
        printf("| %-8d | %-12d | %-48s |\n",
               books[i].id, books[i].price, books[i].title);
    }
    printf("+----------+--------------+--------------------------------------------------+\n");
}

int main() {
    book_t books[6] = {
        {1, 1000, "All the Light We Cannot See"},
        {2, 300,  "The 38 Letters from J.D. Rockefeller to his son"},
        {3, 1000, "The Ballad of Songbirds and Snakes"},
        {4, 550,  "Killers of the Flower Moon"},
        {5, 870,  "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };

    int n = 6;

    // 以表格形式輸出書籍資料與總價至螢幕
    list_books(books, n);
    total_price(books, n);

    // 儲存書籍資料至二進位檔案 Book.bin
    FILE *fp = fopen("Book.bin", "wb");
    if (fp == NULL) {
        printf("無法建立 Book.bin\n");
        return 1;
    }
    fwrite(books, sizeof(book_t), n, fp);
    fclose(fp);

    return 0;
}
