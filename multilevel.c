#include <stdio.h>
#include <conio.h>

struct st {
    char dname[10];              // Directory name
    char sdname[10][10];         // Subdirectory names
    char fname[10][10][10];      // File names within subdirectories
    int ds;                      // Number of subdirectories
    int sds[10];                 // Number of files in each subdirectory
} dir[10];

int main() {
    int i, j, k, n;
    
    printf("Enter number of directories: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter directory %d names: ", i + 1);
        scanf("%s", &dir[i].dname);

        printf("Enter size of %d directories: ", i);
        scanf("%d", &dir[i].ds);

        for (j = 0; j < dir[i].ds; j++) {
            printf("Enter subdirectory name and size: ");
            scanf("%s", &dir[i].sdname[j]);
            scanf("%d", &dir[i].sds[j]);

            for (k = 0; k < dir[i].sds[j]; k++) {
                printf("Enter file name: ");
                scanf("%s", &dir[i].fname[j][k]);
            }
        }
    }

    printf("\nDirectory name\t\tSize\tSubdirectory name\tSize\tFiles");
    printf("\n*****************************************************\n");

    for (i = 0; i < n; i++) {
        printf("%s\t\t%d", dir[i].dname, dir[i].ds);
        
        for (j = 0; j < dir[i].ds; j++) {
            printf("\t%s\t\t%d\t", dir[i].sdname[j], dir[i].sds[j]);
            for (k = 0; k < dir[i].sds[j]; k++) {
                printf("%s\t", dir[i].fname[j][k]);
            }
            printf("\n\t\t");
        }
        printf("\n");
    }
    
    getch(); // Pause the console.
}
