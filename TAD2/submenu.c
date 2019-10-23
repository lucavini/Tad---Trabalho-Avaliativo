
int menuPrincipal(){
    printf("\n1 Cadastro");
    printf("\n2 Imagem");
    printf("\n0 Sair");
    
    int opc;
    scanf("%d", &opc);
    return opc;
}

void main(){
    srand(time(NULL));


    do{
        int opc = menuPrincipal();
        switch (opc){
            case 1:
                
            break;
            
            case 2:
                IMAGEM();
            break;
        
        }
    }
    

}