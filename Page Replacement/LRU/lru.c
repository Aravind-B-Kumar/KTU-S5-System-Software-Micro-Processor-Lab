#include <stdio.h>

void main() {
    int i, j, n, f, in[20], pf = 0, out[10], time[10], least, flag;

    printf("Enter size of input string: ");
    scanf("%d", &n);

    printf("Enter the string elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (j = 0; j < f; j++) {
        out[j] = -1; 
        time[j] = 0; 
    }

    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < f; j++) {
            if (out[j] == in[i]) {
                flag = 1;
                time[j] = i + 1; 
                break;
            }
        }

        if (flag == 0) {
            int emptyFrameFound = 0;
            for (j = 0; j < f; j++) {
                if (out[j] == -1) { 
                    out[j] = in[i]; 
                    time[j] = i + 1; 
                    emptyFrameFound = 1;
                    break;
                }
            }
            if (!emptyFrameFound) {
                if (i >= f) {
                    least = 0;
                    for (j = 1; j < f; j++) {
                        if (time[j] < time[least]) {
                            least = j;
                        }
                    }
                    out[least] = in[i];
                    time[least] = i + 1;
                }
            }
            pf++; 
        }

        for (j = 0; j < f; j++) {
            printf("%d\t", out[j]);
        }
        printf("\tTotal page faults: %d\n", pf);
    }
    
    printf("No. of page hits:%d\n", n - pf);
}
