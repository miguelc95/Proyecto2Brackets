//Autores: Jose Carmelo Ramirez Beltran A01175987 y Miguel Cuellar A01280736
//Fecha: 20/04/2016
//Programa: Proyecto 2E - Brackets
//Clase: Algoritmos


#include <iostream>
#include <string>
using namespace std;

int iMat[10001][10001], iBalanceString=0, iNumCombinaciones=0;

void inicializarMatriz(int iTam)
{
    for(int i=0; i<=iTam; i++)
    {
        for(int j=0; j<=iTam;j++)
        {
            iMat[i][j] = 0;
        }
    }
}

void matrizCombinaciones(int iCantCar, int iCantDada)
{
    int iDif;
    
    iDif = iCantCar - iCantDada;
    
    inicializarMatriz(iCantCar);
    
    
    
    for(int i=0; i<=9999; i++)
    {
        for(int j=0; j<=9999; j++)
        {
            if(j <= i)
                iMat[i][j] = 0;
            else if (j%2==0 && i%2!=0)iMat[i][j]=0;
            else if (i%2==0 && j%2!=0)iMat[i][j]=0;
            else
            {
                iMat[i][j]= iMat[i-1][j-1] + iMat[i-1][j+1];
            }
        }
    }
    iMat[0][0] = 1;
    
    for (int ix=0; ix<iCantCar; ix++) {
        for (int iy=0; iy<iCantDada; iy++) {
            cout<<iMat[ix][iy]<<" ";
        }
        cout<<endl;
    }
}

void calcularBalance(string sString)
{
    for(int i=0; i<sString.length(); i++)
    {
        if(sString[i] == '[')iBalanceString++;
        else iBalanceString--;
    }
}

void solucionCombinaciones(int iCantCar, int iCantDada)
{
    int iDif;
    iDif = iCantCar - iCantDada;
    
    for(int i=0; i<=iDif; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j >= iBalanceString && j >= 0)
            {
                iNumCombinaciones += iMat[i][j] * iMat[iDif-i][j+iBalanceString];
            }
        }
    }
}

int main() {
    
    string sStringBrackets;
    int iCantCar, iCantDada;
    
    cin>>iCantCar>>iCantDada;
    cin>>sStringBrackets;
    for (int i=0; i<10000; i++) {
        iMat[i][i]=1;
    }
    matrizCombinaciones(iCantCar, iCantDada);
    calcularBalance(sStringBrackets);
    solucionCombinaciones(iCantCar, iCantDada);
    cout<<iNumCombinaciones<<endl;
    return 0;
}