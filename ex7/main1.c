#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩:");
    scanf("%d", &n);

    if (n < 1 || n > 5) {
        printf("輸入錯誤，請輸入 1 到 5 之間的數字。\n");
        return 1;
    }

    FILE *fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        printf("無法建立 lotto.txt\n");
        return 1;
    }
    time_t curtime;
    time(&curtime);
    char *time_str = ctime(&curtime);
    for (int i = 0; time_str[i] != '\0'; i++) {
        if (time_str[i] == '\n') {
            time_str[i] = '\0';
            break;
        }
    }

    srand((unsigned)time(NULL));

    fprintf(fp, "========= lotto649 =========\n");
    fprintf(fp, "= %s =\n", time_str);

    for (int i = 1; i <= 5; i++) {
        fprintf(fp, "[%d]: ", i);
        if (i <= n) {
            int nums[7];
            // 產生 7 個 01~69 不重複的亂數
            for (int j = 0; j < 7; j++) {
                int r, duplicate;
                do { duplicate = 0;
                    r = rand() % 69 + 1;
                    for (int k = 0; k < j; k++) {
                        if (nums[k] == r) {
                            duplicate = 1;
                            break;
                        }
                    }
                } while (duplicate);
                nums[j] = r;
            }
            for (int a = 0; a < 5; a++) {
                for (int b = 0; b < 5 - a; b++) {
                    if (nums[b] > nums[b + 1]) {
                        int tmp = nums[b];
                        nums[b] = nums[b + 1];
                        nums[b + 1] = tmp;
                    }
                }
            }

            for (int j = 0; j < 7; j++) {
                fprintf(fp, "%02d ", nums[j]);
            }
            fprintf(fp, "\n");
        } else {
            fprintf(fp, "-- -- -- -- -- -- -- \n");
        }
    }

    fprintf(fp, "========= csie@CGU =========\n");
    fclose(fp);
    printf("以為您購買的%d組樂透組合輸出至 lotto.txt\n", n);
    return 0;
}
