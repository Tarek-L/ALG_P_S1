#include <stdio.h>
#include <stdlib.h>

void spiral_mat_sort(int mat[][4], int size){

  int sorted = 0, turn = 0, dir = 1, end = size, i = 0, j = 0;

  for (int k = 0; k < 15; k++) {

    for (int iteration = 1; iteration < end; iteration ++) {

      printf("%d\n",mat[i][j]);
      printf("i = %d,j = %d\n",i,j);

      if (turn % 2) {
        i = i + dir;
      }
      else {
        j = j + dir;
      }

    } 
    
//    printf("turn : %d\n",turn);
//    printf("end : %d\n",end);
//    printf("dir : %d\n",dir);

    turn = (turn + 1) % 4;
    if ( turn == 3) {
      end --;
    }
    dir = (turn > 1) ? -1 : 1;


    //if (end == 1){break;} 
  }


}

int main()
{
  int matrice[][4] = {{1,2,3,1},{4,5,6,1},{7,8,9,1},{10,11,12,1}};

  spiral_mat_sort(matrice,4);

  return 0;
}
