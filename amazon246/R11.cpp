
/*****************************************************************
 *                                                               *
 * *******************Matrix operations************************* *
 *          ******       -> Spiral form        ******            *
 *          *            -> Transpose               *            *
 *          *            -> Multipy                 *            *
 *          ******       -> Other              ******            *
 *                                                               *
 *                                  @author: Ashutosh Godara     *
 *****************************************************************/
#include "amazon.h"
int main(){
    int r,c,i,j,op;
    cout<<"Enter No. of Rows and Coloums int Matrix:";
    cin>>r>>c;
    int **mat = new int*[r];
    for(i=0;i<r;i++) mat[i] = new int[c];
    //int mat[r][c];
    /*int **mat= (int**)malloc(r*sizeof(int*));
    for(i=0;i<r;i++){
        mat[i]=(int*)malloc(c*sizeof(int));
    }*/
    cout<<"Enter elements in Matrix."<<endl;
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++){
            cin>>mat[i][j];
        }
        //cout<<*mat[i]+j-1<<endl;
    }
    cout<<endl;
    char y;
    cout<<"\nEnter option for operation to perform on Matrix."<<endl;
    do{
        cout<<"1 for Spiral form print."<<endl;
        cout<<"2 for Transpose of matrix."<<endl;
        cout<<"3 for Multipy of Matrix with same or another Matrix"<<endl;
        cout<<"4 for print matrix."<<endl;
        cin>>op;
        switch(op) {
            case 1:
                spiral_print(mat,r,c);
                break;
            case 2:
                transpose_matrix(mat,r,c);
                break;
            case 3:
                multiply(mat);
                break;
            case 4:
                print_matrix(mat,r,c);
                break;
            default:
                cout<<"Invalid input try again"<<endl;
                break;
        }
        cout<<"\nWanted new operation Y/N?";
        cin>>y;
        cout<<endl;
    }while(y == 'y' || y == 'Y');

    return 0;
}
void spiral_print(int **mat,int r,int c){
    int i,j,k,z,p;
    for(i=0;i<r;i++){
        for(j=i;j<c-i;j++) {
            cout<<mat[i][j]<<" ";
        }j--;
        for(z=i+1;z<r-i;z++) {
            cout<<mat[z][j]<<" ";
        }z--;
        for(k=j-1;k>=i;k--){
            cout<<mat[z][k]<<" ";
        }k++;
        for(p=z-1;p>i;p--) {
            cout<<mat[p][k]<<" ";
        }
    }



}
void transpose_matrix(int **mat,int r,int c){
    int **TM=(int**)malloc(r*sizeof(int*));
    int i,j;
    for(i=0;i<r;i++){
        TM[i]= (int*)malloc(c*sizeof(int));
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            //swap(&mat[i][j],&mat[j][i]);
            TM[i][j]=mat[i][j];
        }
    }
    for(i=0;i<r;i++) {
        for(j=i;j<c;j++) {
            if(i!=j)
            swap(&TM[i][j],&TM[j][i]);
        }
    }
    print_matrix(TM,r,c);
}
void print_matrix(int **mat,int r,int c) {
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
void multiply(int **mat){
}
