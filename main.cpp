#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

string encriptacion(string);


int main()
{
    int ingreso, val;
    string validacion, clave, clavein, clavenc;
    ofstream Guardar;
    ifstream Leer;
    cout << "ingrese el loggin como usuario digitando 1 o como administrador digitando 2" << endl;
    cin>>ingreso;
    if(ingreso==1){
        validacion="usuario";
        val=1;
    }
    if(ingreso==2){
        validacion="administrador";    //AbCd
        val=2;

    }
    switch(val){
    case (1):{

    }
    case(2):{//administrador
        bool itero=false;
        Leer.open("../practica3_2/BD/sudo.txt");
        if(!Leer.is_open()){
            cout << "Error abriendo el archivo" << endl;
            exit(1);
        }
        while(itero==false){
        Leer>>clave;
        cout<<"ingrese la clave para entrar como administrador";
        cin>>clavein;
        if (clavein=="1"){
            break;
        }
        clavenc=encriptacion(clavein);
        if(clavenc==clave){
            cout<<"bienvenido administrador"<<endl;
            itero=true;
        }
        else{
            cout<<"por favor ingrese la clave correcta o oprima 1 para salir"<<endl;
        }
        }
    }
    }

}
string encriptacion(string a){
    int arreglo[4];
    int psuba=0;//itera en el string
    char suba=a.at(psuba);//string que sera iterado
    int conv=suba;//convierto a entero ascii
    string strbinario, strencriptado,str;
    for (int i=0; i<a.length(); i++){
        conv=a.at(psuba);
        for(int e=7; e>=0; e--){
            if(pow(2,e)<=conv){
                arreglo[7-e]=1;//ubica los 1s en el arrglo
                conv-=pow(2,e);
                strbinario+="1";
            }
            else{
                arreglo[7-e]=0;//ubica los 0s en el arreglo
                strbinario+="0";
            }
        }
            psuba+=1;
    }
    for (int o=0; o<strbinario.length()-1;o++) {
        if (o==0){
            strencriptado+=strbinario.at(strbinario.length()-1);
        }
        str=strbinario.at(o);
        strencriptado+=str;
    }
    return(strencriptado);
}

